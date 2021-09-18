#include <iostream>
#include <tuple>
#include <map>

using namespace std;

class TeamTasks {
public:
  /// Person --> statistic of tasks statuses
  const TasksInfo& GetPersonTasksInfo (const string& person) const {
    return TeamInfo.at(person);
  }

  void AddNewTask(const string& person) {
    ++TeamInfo[person][TaskStatus::NEW];
  }

  /// update statuses of task_count tasks for person
  /// first TaskInfo --> updated tasks
  /// second TaskInfo --> NOT updated tasks
  /// GARANTED : person has tasks, IF (task_count >= tasks) --> OK, let it = tasks
  tuple<TasksInfo, TasksInfo> PerformPersonTasks (const string& person, int task_count) {
    /// task_count ---> update tasks back-to-back, beginning from NEW
    TasksInfo updated, not_updated;
    if (TeamInfo.count(person)) {
      /// count updated
      for (; task_count; --task_count) {
        /// check all except DONE
	if (TeamInfo[person].count(TaskStatus::NEW) > 0 &&
	    TeamInfo[person][TaskStatus::NEW] > 0) {
          --TeamInfo[person][TaskStatus::NEW];
	  ++updated[TaskStatus::IN_PROGRESS];
        } else if (TeamInfo[person].count(TaskStatus::IN_PROGRESS) > 0 &&
		   TeamInfo[person][TaskStatus::IN_PROGRESS] > 0) {
          --TeamInfo[person][TaskStatus::IN_PROGRESS]; 
	  ++updated[TaskStatus::TESTING];
        } else if (TeamInfo[person].count(TaskStatus::TESTING) > 0 &&
	           TeamInfo[person][TaskStatus::TESTING] > 0) {
          --TeamInfo[person][TaskStatus::TESTING];
	  ++updated[TaskStatus::DONE];
        } else {
          break;
	}
      }
      
      /// count NOT updated
      if (TeamInfo[person].count(TaskStatus::NEW) > 0 &&
          TeamInfo[person][TaskStatus::NEW] > 0) {
        not_updated[TaskStatus::NEW] = TeamInfo[person][TaskStatus::NEW];
      }
      
      if (TeamInfo[person].count(TaskStatus::IN_PROGRESS) > 0 &&
	  TeamInfo[person][TaskStatus::IN_PROGRESS] > 0) {
        not_updated[TaskStatus::IN_PROGRESS] = TeamInfo[person][TaskStatus::IN_PROGRESS];
      }
      
      if (TeamInfo[person].count(TaskStatus::TESTING) > 0 &&
	  TeamInfo[person][TaskStatus::TESTING] > 0) {
        not_updated[TaskStatus::TESTING] = TeamInfo[person][TaskStatus::TESTING];
      }

      /// change statuses
      if (updated.count(TaskStatus::IN_PROGRESS) > 0) {
        TeamInfo[person][TaskStatus::IN_PROGRESS] += updated[TaskStatus::IN_PROGRESS];
      }
      
      if (updated.count(TaskStatus::TESTING) > 0) {
        TeamInfo[person][TaskStatus::TESTING] += updated[TaskStatus::TESTING];
      }
      
      if (updated.count(TaskStatus::DONE) > 0) {
        TeamInfo[person][TaskStatus::DONE] += updated[TaskStatus::DONE];
      }
     
      /// erase statuses without tasks
      if (TeamInfo[person].count(TaskStatus::NEW) > 0) {
        if (TeamInfo[person][TaskStatus::NEW] == 0) {
          TeamInfo[person].erase(TaskStatus::NEW);
	}
      }
      
      if (TeamInfo[person].count(TaskStatus::IN_PROGRESS) > 0) {
        if (TeamInfo[person][TaskStatus::IN_PROGRESS] == 0) {
          TeamInfo[person].erase(TaskStatus::IN_PROGRESS);
	}
      }
      
      if (TeamInfo[person].count(TaskStatus::TESTING) > 0) {
        if (TeamInfo[person][TaskStatus::TESTING] == 0) {
          TeamInfo[person].erase(TaskStatus::TESTING);
	}
      }

      if (TeamInfo[person].count(TaskStatus::DONE) > 0) {
        if (TeamInfo[person][TaskStatus::DONE] == 0) {
          TeamInfo[person].erase(TaskStatus::DONE);
	}
      }

    }
    return make_tuple(updated, not_updated);
  }
private:
  /// person --> TaskInfo
  map<string, TasksInfo> TeamInfo;
};

