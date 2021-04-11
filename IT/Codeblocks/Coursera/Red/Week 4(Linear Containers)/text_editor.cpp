#include <string>
#include "test_runner.h"
#include "profile.h"

using namespace std;

class Editor {
private:
  string text;
  //string::iterator pos;
  size_t pos;
  string buffer;
public:
  // Реализуйте конструктор по умолчанию и объявленные методы
  Editor() : text(""), pos( 0 /*text.begin()*/), buffer("") {}
  
  void Left() {if (pos != 0/*text.begin()*/) --pos;}
  void Right() {if (pos != text.size()/*end()*/) ++pos;}

  void Insert(char token) {
      text.insert(pos + text.begin(), token);
      Right();
  }
  
  void Cut(size_t tokens = 1) {
      Copy(tokens);
      text.erase(pos + text.begin(), pos + text.begin() + min(tokens, size_t(text.size() - pos)));
  }

  void Copy(size_t tokens = 1) {
      buffer = text.substr(pos, min(tokens, size_t(text.size() - pos)));
  }

  void Paste() {
    text.insert(pos + text.begin(), buffer.begin(), buffer.end());
    pos += buffer.size();
  }

  string GetText() const {
    return text;
  }
};

void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}






void TestEditing() {
  {
    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");
    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len);
    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", ");
    editor.Paste();
    editor.Left();
    editor.Left();
    editor.Cut(3);
    
    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;
    
    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();
    
    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }
  
  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");
  
  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "example");
}

void TestCopyPasteLastChars()
{
    Editor editor;
    TypeText(editor, "happy birthday");
    editor.Left();
    editor.Left();
    editor.Copy(5);
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "happy birthdayay");
}

void TestCut()
{
	Editor editor;
	//1
	editor.Cut(10);
	editor.Insert('a');
	editor.Left();
	//2
	editor.Cut(1);
	ASSERT_EQUAL(editor.GetText(), "");
	editor.Paste();
	ASSERT_EQUAL(editor.GetText(), "a");
	//3
	editor.Cut(0);
	editor.Paste();
	ASSERT_EQUAL(editor.GetText(), "a");
	TypeText(editor, "bcde");
	editor.Left();editor.Left();editor.Left();editor.Left();editor.Left();
	//4
	editor.Cut(10);
	ASSERT_EQUAL(editor.GetText(), "");
	editor.Paste();
	ASSERT_EQUAL(editor.GetText(), "abcde");
	editor.Left();editor.Left();editor.Left();editor.Left();editor.Left();
	//5
	editor.Cut(5);
	ASSERT_EQUAL(editor.GetText(), "");
	editor.Paste();
	//6
	editor.Left();editor.Left();editor.Left();editor.Left();editor.Left();
	editor.Cut(1);
	ASSERT_EQUAL(editor.GetText(), "bcde");
	editor.Right();
	editor.Cut(1);
	ASSERT_EQUAL(editor.GetText(), "bde");
	editor.Cut(1);
	editor.Cut(1);
	ASSERT_EQUAL(editor.GetText(), "b");
}

void TestCopy()
{
	Editor editor;
	//1
	editor.Copy(10);
	editor.Insert('a');
	editor.Paste();
	editor.Left();
	ASSERT_EQUAL(editor.GetText(), "a");
	//2
	editor.Copy(1);
	editor.Paste();
	ASSERT_EQUAL(editor.GetText(), "aa");//between a
    //3
	editor.Copy(0);
	editor.Paste();
	ASSERT_EQUAL(editor.GetText(), "aa");
	TypeText(editor, "bcde");
	editor.Left();editor.Left();editor.Left();editor.Left();editor.Left();editor.Left();
	//4
	editor.Cut(10);
	ASSERT_EQUAL(editor.GetText(), "");
	editor.Paste();
	ASSERT_EQUAL(editor.GetText(), "abcdea");
}

void FirstTest () {
  Editor editor;
  const string text = "hello, world";
  for (char c : text) {
    editor.Insert(c);
  }
  // Текущее состояние редактора: `hello, world|`
  for (size_t i = 0; i < text.size(); ++i) {
    editor.Left();
  }
  // Текущее состояние редактора: `|hello, world`
  editor.Cut(7);
  // Текущее состояние редактора: `|world`
  // в буфере обмена находится текст `hello, `
  for (size_t i = 0; i < 5; ++i) {
    editor.Right();
  }
  // Текущее состояние редактора: `world|`
  editor.Insert(',');
  editor.Insert(' ');
  // Текущее состояние редактора: `world, |`
  editor.Paste();
  // Текущее состояние редактора: `world, hello, |`
  editor.Left();
  editor.Left();
  //Текущее состояние редактора: `world, hello|, `
  editor.Cut(3); // Будут вырезаны 2 символа
  // Текущее состояние редактора: `world, hello|`
  ASSERT_EQUAL(editor.GetText(), "world, hello" );
}



void MyTest1 () {
  Editor editor;
  
  editor.Left();
  editor.Left();
  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Right();
  editor.Right();
  editor.Right();
  editor.Right();
  
  const string s = "hello, my name is Vik";
  TypeText(editor, s);
  for (size_t i = 0; i <= s.size() + 3; ++i) {
    editor.Left();
  }
  
  editor.Cut(7);
  ASSERT_EQUAL(editor.GetText(), "my name is Vik");
}

int main() {
  LOG_DURATION("total");	
  TestRunner tr;

  RUN_TEST(tr, MyTest1);
  RUN_TEST(tr, FirstTest);

  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);
  RUN_TEST(tr, TestCopyPasteLastChars);
  RUN_TEST(tr, TestCut);
  RUN_TEST(tr, TestCopy);
  return 0;
}
