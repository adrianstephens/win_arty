#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace Payments {
enum class PaymentRequestStatus : int {
	Succeeded = 0,
	Failed = 1,
	Canceled = 2,
};
enum class PaymentRequestCompletionStatus : int {
	Succeeded = 0,
	Failed = 1,
	Unknown = 2,
};
enum class PaymentRequestChangeKind : int {
	ShippingOption = 0,
	ShippingAddress = 1,
};
enum class PaymentOptionPresence : int {
	None = 0,
	Optional = 1,
	Required = 2,
};
enum class PaymentShippingType : int {
	Shipping = 0,
	Delivery = 1,
	Pickup = 2,
};
enum class PaymentCanMakePaymentResultStatus : int {
	Unknown = 0,
	Yes = 1,
	No = 2,
	NotAllowed = 3,
	UserNotSignedIn = 4,
	SpecifiedPaymentMethodIdsNotSupported = 5,
	NoQualifyingCardOnFile = 6,
};
struct IPaymentRequest;
struct IPaymentMerchantInfoFactory;
struct IPaymentMerchantInfo;
struct PaymentMerchantInfo;
struct IPaymentDetailsFactory;
struct IPaymentDetails;
struct PaymentDetails;
struct IPaymentMethodDataFactory;
struct IPaymentMethodData;
struct PaymentMethodData;
struct IPaymentOptions;
struct PaymentOptions;
struct IPaymentRequest2;
struct IPaymentRequestFactory;
struct IPaymentRequestFactory2;
struct PaymentRequest;
struct IPaymentResponse;
struct IPaymentTokenFactory;
struct IPaymentToken;
struct PaymentToken;
struct IPaymentShippingOptionFactory;
struct IPaymentShippingOption;
struct PaymentShippingOption;
struct IPaymentAddress;
struct PaymentAddress;
struct IPaymentItemFactory;
struct IPaymentItem;
struct PaymentItem;
struct IPaymentDetailsModifierFactory;
struct IPaymentDetailsModifier;
struct PaymentDetailsModifier;
struct IPaymentCurrencyAmount;
struct IPaymentCurrencyAmountFactory;
struct PaymentCurrencyAmount;
struct IPaymentRequestChangedArgs;
struct IPaymentRequestChangedResultFactory;
struct IPaymentRequestChangedResult;
struct PaymentRequestChangedResult;
struct PaymentRequestChangedHandler;
struct PaymentRequestChangedArgs;
struct IPaymentMediator;
struct IPaymentRequestSubmitResult;
struct PaymentRequestSubmitResult;
struct IPaymentMediator2;
struct IPaymentCanMakePaymentResultFactory;
struct IPaymentCanMakePaymentResult;
struct PaymentCanMakePaymentResult;
struct PaymentResponse;
struct PaymentMediator;
}}}
} // namespace iso_winrt
