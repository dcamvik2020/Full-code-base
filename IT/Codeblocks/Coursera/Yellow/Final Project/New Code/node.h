#pragma once

#include <memory>
#include "date.h"
#include "token.h"
//#include "condition_parser.h"

enum class Comparison {
  Less,
  LessOrEqual,
  Greater,
  GreaterOrEqual,
  Equal,
  NotEqual,
};


class Node {
public:
  virtual bool Evaluate(const Date& date,
          const string& event) const = 0;
};


class EmptyNode : public Node {
public:
  EmptyNode() {};
  bool Evaluate(const Date& date,
          const string& event) const override {
    /// for compilability
    return true || bool(date.GetYear() && event.empty());
  }
};


class DateComparisonNode : public Node {
private:
  Comparison cmp_;
  Date date_;
public:
  DateComparisonNode(Comparison cmp,
      Date date) : cmp_(cmp), date_(date) {}
  bool Evaluate(const Date& date,
          const string& event) const override;
};


class EventComparisonNode : public Node {
private:
  Comparison cmp_;
  const string value_;
public:
  EventComparisonNode(Comparison cmp,
      const string & value) : cmp_(cmp), value_(value) {}
  bool Evaluate(const Date& date,
          const string& event) const override;
};


enum class LogicalOperation {
  And,
  Or,
};


class LogicalOperationNode : public Node {
private:
  const LogicalOperation op_;
  shared_ptr<Node> left_;
  shared_ptr<Node> right_;
public:
  LogicalOperationNode(const LogicalOperation op,
      shared_ptr<Node> left, shared_ptr<Node> right)
      : op_(op), left_(left), right_(right) {}

  bool Evaluate(const Date& date,
          const string& event) const override; 
};
