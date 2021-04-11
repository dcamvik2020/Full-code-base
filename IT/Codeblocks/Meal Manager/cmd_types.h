#ifndef CMD_TYPES_H
#define CMD_TYPES_H

enum class CommandType {
  ADD_NEW_MEAL = 0,             // add/new + meal  ,  eat

  CORRECT_LAST_MEAL,        // edit last + meal/-
  CORRECT_ANY_MEAL,         // edit meal

  SHOW_LAST_MEAL,           // show/- + last          + meal/-
  SHOW_LAST_DAY,            // show/- + last          + day/-
  SHOW_k_LAST_MEALS,        // show/- + some/several  + last meals
  SHOW_k_LAST_DAYS,         // show/- + some/several  + last days
  SHOW_ANY_MEAL,            // show/- + meal
  SHOW_ANY_DAY,             // show/- + day
  SHOW_PERIOD,              // show/- + days/- + from + day1 to daye2/today/-
  SHOW_HISTORY,             // show/- + (all + days/-) / history

  COUNT_MEALS_IN_LAST_DAY,  // count meals in last + day/-
  COUNT_MEALS_IN_ANY_DAY,   // count meals + (in day) / -
  COUNT_ALL_MEALS,          // count (all meals) / (meals in history)

  DELETE_LAST_MEAL,         // delete last (+ day/-)
  DELETE_LAST_DAY,          // delete
  DELETE_k_LAST_MEALS,      // delete
  DELETE_k_LAST_DAYS,       // delete
  DELETE_ANY_MEAL,          // delete
  DELETE_ANY_DAY,           // delete
  DELETE_PERIOD,            // delete
  DELETE_HISTORY,           // (delete + history/all) / (clear history)
 
  HELP,                     // help, man 
  WRONG_COMMAND = -1,       // any wrong command ()
};

#endif
