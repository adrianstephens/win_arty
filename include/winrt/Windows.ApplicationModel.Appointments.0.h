#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace Appointments {
struct IAppointmentManagerStatics;
enum class AppointmentDetailsKind : int {
	PlainText = 0,
	Html = 1,
};
enum class AppointmentParticipantResponse : int {
	None = 0,
	Tentative = 1,
	Accepted = 2,
	Declined = 3,
	Unknown = 4,
};
enum class AppointmentSensitivity : int {
	Public = 0,
	Private = 1,
};
enum class AppointmentBusyStatus : int {
	Busy = 0,
	Tentative = 1,
	Free = 2,
	OutOfOffice = 3,
	WorkingElsewhere = 4,
};
struct IAppointment;
struct IAppointment2;
struct IAppointment3;
struct Appointment;
enum class AppointmentStoreAccessType : int {
	AppCalendarsReadWrite = 0,
	AllCalendarsReadOnly = 1,
	AllCalendarsReadWrite = 2,
};
struct IAppointmentManagerStatics2;
enum class FindAppointmentCalendarsOptions : unsigned {
	None = 0x0,
	IncludeHidden = 0x1,
};
struct IAppointmentStore3;
struct IAppointmentStore;
struct IAppointmentStore2;
struct AppointmentStore;
struct IAppointmentManagerStatics3;
struct IAppointmentManagerForUser;
struct AppointmentManagerForUser;
enum class AppointmentParticipantRole : int {
	RequiredAttendee = 0,
	OptionalAttendee = 1,
	Resource = 2,
};
struct IAppointmentParticipant;
struct AppointmentOrganizer;
struct IAppointmentInvitee;
struct AppointmentInvitee;
enum class AppointmentRecurrenceUnit : int {
	Daily = 0,
	Weekly = 1,
	Monthly = 2,
	MonthlyOnDay = 3,
	Yearly = 4,
	YearlyOnDay = 5,
};
enum class AppointmentDaysOfWeek : unsigned {
	None = 0x0,
	Sunday = 0x1,
	Monday = 0x2,
	Tuesday = 0x4,
	Wednesday = 0x8,
	Thursday = 0x10,
	Friday = 0x20,
	Saturday = 0x40,
};
enum class AppointmentWeekOfMonth : int {
	First = 0,
	Second = 1,
	Third = 2,
	Fourth = 3,
	Last = 4,
};
enum class AppointmentCalendarSyncStatus : int {
	Idle = 0,
	Syncing = 1,
	UpToDate = 2,
	AuthenticationError = 3,
	PolicyError = 4,
	UnknownError = 5,
	ManualAccountRemovalRequired = 6,
};
struct IAppointmentRecurrence;
enum class RecurrenceType : int {
	Master = 0,
	Instance = 1,
	ExceptionInstance = 2,
};
struct IAppointmentRecurrence2;
struct IAppointmentRecurrence3;
struct AppointmentRecurrence;
struct AppointmentManager;
struct IFindAppointmentsOptions;
enum class AppointmentSummaryCardView : int {
	System = 0,
	App = 1,
};
enum class AppointmentCalendarOtherAppReadAccess : int {
	SystemOnly = 0,
	Limited = 1,
	Full = 2,
	None = 3,
};
enum class AppointmentCalendarOtherAppWriteAccess : int {
	None = 0,
	SystemOnly = 1,
	Limited = 2,
};
struct IAppointmentCalendar;
struct FindAppointmentsOptions;
struct IAppointmentException;
struct AppointmentException;
struct IAppointmentCalendar2;
struct IAppointmentCalendarSyncManager2;
struct IAppointmentCalendarSyncManager;
struct AppointmentCalendarSyncManager;
struct IAppointmentCalendar3;
struct IAppointmentPropertiesStatics;
struct IAppointmentPropertiesStatics2;
enum class AppointmentConflictType : int {
	None = 0,
	Adjacent = 1,
	Overlap = 2,
};
struct IAppointmentConflictResult;
enum class AppointmentStoreChangeType : int {
	AppointmentCreated = 0,
	AppointmentModified = 1,
	AppointmentDeleted = 2,
	ChangeTrackingLost = 3,
	CalendarCreated = 4,
	CalendarModified = 5,
	CalendarDeleted = 6,
};
struct IAppointmentStoreChange;
struct IAppointmentStoreChange2;
struct AppointmentCalendar;
struct IAppointmentStoreChangeReader;
struct AppointmentStoreChange;
struct IAppointmentStoreChangeTracker;
struct AppointmentStoreChangeReader;
struct IAppointmentStoreChangeTracker2;
struct IAppointmentStoreChangedEventArgs;
struct IAppointmentStoreChangedDeferral;
struct AppointmentStoreChangedDeferral;
struct IAppointmentStoreNotificationTriggerDetails;
struct AppointmentStoreChangeTracker;
struct AppointmentConflictResult;
struct AppointmentStoreChangedEventArgs;
struct AppointmentProperties;
struct AppointmentStoreNotificationTriggerDetails;
}}}
} // namespace iso_winrt