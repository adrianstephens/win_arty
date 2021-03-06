#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace Email {
enum class EmailCertificateValidationStatus : int {
	Success = 0,
	NoMatch = 1,
	InvalidUsage = 2,
	InvalidCertificate = 3,
	Revoked = 4,
	ChainRevoked = 5,
	RevocationServerFailure = 6,
	Expired = 7,
	Untrusted = 8,
	ServerError = 9,
	UnknownFailure = 10,
};
enum class EmailStoreAccessType : int {
	AppMailboxesReadWrite = 0,
	AllMailboxesLimitedReadWrite = 1,
};
enum class EmailMessageBodyKind : int {
	Html = 0,
	PlainText = 1,
};
enum class EmailAttachmentDownloadState : int {
	NotDownloaded = 0,
	Downloading = 1,
	Downloaded = 2,
	Failed = 3,
};
enum class EmailMessageDownloadState : int {
	PartiallyDownloaded = 0,
	Downloading = 1,
	Downloaded = 2,
	Failed = 3,
};
enum class EmailSpecialFolderKind : int {
	None = 0,
	Root = 1,
	Inbox = 2,
	Outbox = 3,
	Drafts = 4,
	DeletedItems = 5,
	Sent = 6,
};
enum class EmailQueryKind : int {
	All = 0,
	Important = 1,
	Flagged = 2,
	Unread = 3,
	Read = 4,
	Unseen = 5,
};
enum class EmailMailboxChangeType : int {
	MessageCreated = 0,
	MessageModified = 1,
	MessageDeleted = 2,
	FolderCreated = 3,
	FolderModified = 4,
	FolderDeleted = 5,
	ChangeTrackingLost = 6,
};
enum class EmailQuerySortDirection : int {
	Descending = 0,
	Ascending = 1,
};
enum class EmailQuerySortProperty : int {
	Date = 0,
};
enum class EmailQuerySearchFields : unsigned {
	None = 0x0,
	Subject = 0x1,
	Sender = 0x2,
	Preview = 0x4,
	Recipients = 0x8,
	All = 0xFFFFFFFF,
};
enum class EmailBatchStatus : int {
	Success = 0,
	ServerSearchSyncManagerError = 1,
	ServerSearchUnknownError = 2,
};
enum class EmailMessageResponseKind : int {
	None = 0,
	Reply = 1,
	ReplyAll = 2,
	Forward = 3,
};
enum class EmailMeetingResponseType : int {
	Accept = 0,
	Decline = 1,
	Tentative = 2,
};
enum class EmailMailboxActionKind : int {
	MarkMessageAsSeen = 0,
	MarkMessageRead = 1,
	ChangeMessageFlagState = 2,
	MoveMessage = 3,
	SaveDraft = 4,
	SendMessage = 5,
	CreateResponseReplyMessage = 6,
	CreateResponseReplyAllMessage = 7,
	CreateResponseForwardMessage = 8,
	MoveFolder = 9,
	MarkFolderForSyncEnabled = 10,
};
enum class EmailImportance : int {
	Normal = 0,
	High = 1,
	Low = 2,
};
enum class EmailFlagState : int {
	Unflagged = 0,
	Flagged = 1,
	Completed = 2,
	Cleared = 3,
};
enum class EmailMailboxSyncStatus : int {
	Idle = 0,
	Syncing = 1,
	UpToDate = 2,
	AuthenticationError = 3,
	PolicyError = 4,
	UnknownError = 5,
	ManualAccountRemovalRequired = 6,
};
enum class EmailMailboxOtherAppReadAccess : int {
	SystemOnly = 0,
	Full = 1,
	None = 2,
};
enum class EmailMailboxOtherAppWriteAccess : int {
	None = 0,
	Limited = 1,
};
enum class EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation : int {
	None = 0,
	StrongAlgorithm = 1,
	AnyAlgorithm = 2,
};
enum class EmailMailboxSmimeEncryptionAlgorithm : int {
	Any = 0,
	TripleDes = 1,
	Des = 2,
	RC2128Bit = 3,
	RC264Bit = 4,
	RC240Bit = 5,
};
enum class EmailMailboxSmimeSigningAlgorithm : int {
	Any = 0,
	Sha1 = 1,
	MD5 = 2,
};
enum class EmailMailboxAutoReplyMessageResponseKind : int {
	Html = 0,
	PlainText = 1,
};
enum class EmailQuerySearchScope : int {
	Local = 0,
	Server = 1,
};
enum class EmailRecipientResolutionStatus : int {
	Success = 0,
	RecipientNotFound = 1,
	AmbiguousRecipient = 2,
	NoCertificate = 3,
	CertificateRequestLimitReached = 4,
	CannotResolveDistributionList = 5,
	ServerError = 6,
	UnknownFailure = 7,
};
enum class EmailMessageSmimeKind : int {
	None = 0,
	ClearSigned = 1,
	OpaqueSigned = 2,
	Encrypted = 3,
};
enum class EmailMailboxEmptyFolderStatus : int {
	Success = 0,
	NetworkError = 1,
	PermissionsError = 2,
	ServerError = 3,
	UnknownFailure = 4,
	CouldNotDeleteEverything = 5,
};
enum class EmailMailboxCreateFolderStatus : int {
	Success = 0,
	NetworkError = 1,
	PermissionsError = 2,
	ServerError = 3,
	UnknownFailure = 4,
	NameCollision = 5,
	ServerRejected = 6,
};
enum class EmailMailboxDeleteFolderStatus : int {
	Success = 0,
	NetworkError = 1,
	PermissionsError = 2,
	ServerError = 3,
	UnknownFailure = 4,
	CouldNotDeleteEverything = 5,
};
struct IEmailManagerStatics;
struct IEmailMessage4;
struct IEmailMessage3;
struct IEmailMessage2;
struct IEmailMessage;
struct EmailMessage;
struct IEmailManagerStatics2;
struct IEmailStore;
struct EmailStore;
struct IEmailManagerStatics3;
struct IEmailManagerForUser;
struct EmailManagerForUser;
struct IEmailMailbox5;
struct IEmailMailbox4;
struct IEmailMailbox;
struct IEmailMailbox2;
struct IEmailMailbox3;
struct EmailMailbox;
struct IEmailConversationReader;
struct EmailConversationReader;
struct IEmailQueryOptionsFactory;
struct IEmailQueryOptions;
struct EmailQueryOptions;
struct IEmailMessageReader;
struct EmailMessageReader;
struct IEmailConversation;
struct EmailConversation;
struct IEmailFolder;
struct EmailFolder;
struct IEmailRecipient;
struct IEmailRecipientFactory;
struct EmailRecipient;
struct IEmailIrmTemplate;
struct IEmailIrmTemplateFactory;
struct EmailIrmTemplate;
struct IEmailIrmInfo;
struct IEmailIrmInfoFactory;
struct EmailIrmInfo;
struct IEmailAttachmentFactory2;
struct IEmailAttachmentFactory;
struct IEmailAttachment2;
struct IEmailAttachment;
struct EmailAttachment;
struct IEmailMeetingInfo2;
struct IEmailMeetingInfo;
struct EmailMeetingInfo;
struct IEmailMailboxChangedEventArgs;
struct IEmailMailboxChangedDeferral;
struct EmailMailboxChangedDeferral;
struct IEmailStoreNotificationTriggerDetails;
struct IEmailMailboxPolicies;
struct IEmailMailboxPolicies2;
struct IEmailMailboxPolicies3;
struct IEmailMailboxCapabilities;
struct IEmailMailboxCapabilities2;
struct IEmailMailboxCapabilities3;
struct EmailMailboxCapabilities;
struct IEmailMailboxChangeTracker;
struct EmailMailboxChangeTracker;
struct EmailMailboxPolicies;
struct IEmailMailboxSyncManager2;
struct IEmailMailboxSyncManager;
struct EmailMailboxSyncManager;
struct EmailMailboxChangedEventArgs;
struct IEmailMailboxAutoReplySettings;
struct EmailMailboxAutoReplySettings;
struct IEmailRecipientResolutionResult2;
struct IEmailRecipientResolutionResult;
struct EmailRecipientResolutionResult;
struct IEmailMailboxCreateFolderResult;
struct EmailMailboxCreateFolderResult;
struct IEmailMailboxAutoReply;
struct EmailMailboxAutoReply;
struct IEmailItemCounts;
struct EmailItemCounts;
struct IEmailMailboxAction;
struct IEmailQueryTextSearch;
struct EmailQueryTextSearch;
struct IEmailConversationBatch;
struct EmailConversationBatch;
struct IEmailMessageBatch;
struct EmailMessageBatch;
struct IEmailMailboxChange;
struct EmailMailboxAction;
struct IEmailMailboxChangeReader;
struct EmailMailboxChange;
struct EmailMailboxChangeReader;
struct EmailManager;
struct EmailStoreNotificationTriggerDetails;
}}}
} // namespace iso_winrt
