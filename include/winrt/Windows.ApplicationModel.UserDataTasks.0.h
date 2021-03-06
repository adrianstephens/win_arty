#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace UserDataTasks {
enum class UserDataTaskStoreAccessType : int {
	AppTasksReadWrite = 0,
	AllTasksLimitedReadWrite = 1,
};
enum class UserDataTaskListOtherAppReadAccess : int {
	Full = 0,
	SystemOnly = 1,
	None = 2,
};
enum class UserDataTaskListOtherAppWriteAccess : int {
	Limited = 0,
	None = 1,
};
enum class UserDataTaskKind : int {
	Single = 0,
	Recurring = 1,
	Regenerating = 2,
};
enum class UserDataTaskPriority : int {
	Normal = 0,
	Low = -1,
	High = 1,
};
enum class UserDataTaskSensitivity : int {
	Public = 0,
	Private = 1,
};
enum class UserDataTaskDetailsKind : int {
	PlainText = 0,
	Html = 1,
};
enum class UserDataTaskRecurrenceUnit : int {
	Daily = 0,
	Weekly = 1,
	Monthly = 2,
	MonthlyOnDay = 3,
	Yearly = 4,
	YearlyOnDay = 5,
};
enum class UserDataTaskRegenerationUnit : int {
	Daily = 0,
	Weekly = 1,
	Monthly = 2,
	Yearly = 4,
};
enum class UserDataTaskDaysOfWeek : unsigned {
	None = 0x0,
	Sunday = 0x1,
	Monday = 0x2,
	Tuesday = 0x4,
	Wednesday = 0x8,
	Thursday = 0x10,
	Friday = 0x20,
	Saturday = 0x40,
};
enum class UserDataTaskQuerySortProperty : int {
	DueDate = 0,
};
enum class UserDataTaskQueryKind : int {
	All = 0,
	Incomplete = 1,
	Complete = 2,
};
enum class UserDataTaskWeekOfMonth : int {
	First = 0,
	Second = 1,
	Third = 2,
	Fourth = 3,
	Last = 4,
};
enum class UserDataTaskListSyncStatus : int {
	Idle = 0,
	Syncing = 1,
	UpToDate = 2,
	AuthenticationError = 3,
	PolicyError = 4,
	UnknownError = 5,
};
struct IUserDataTaskManagerStatics;
struct IUserDataTaskManager;
struct UserDataTaskManager;
struct IUserDataTaskStore;
struct UserDataTaskStore;
struct IUserDataTaskList;
struct UserDataTaskList;
struct IUserDataTaskQueryOptions;
struct IUserDataTaskListLimitedWriteOperations;
struct UserDataTaskListLimitedWriteOperations;
struct IUserDataTaskListSyncManager;
struct UserDataTaskListSyncManager;
struct IUserDataTaskReader;
struct UserDataTaskReader;
struct UserDataTaskQueryOptions;
struct IUserDataTask;
struct UserDataTask;
struct IUserDataTaskBatch;
struct UserDataTaskBatch;
struct IUserDataTaskRecurrenceProperties;
struct UserDataTaskRecurrenceProperties;
struct IUserDataTaskRegenerationProperties;
struct UserDataTaskRegenerationProperties;
}}}
} // namespace iso_winrt
