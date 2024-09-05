// Copyright Monkeyman Studios


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "UI/WidgetController/OverlayWidgetController.h"


void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is not set in BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass is not set in BP_AuraHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	AuraOverlayWidget = Cast<UAuraUserWidget>(Widget); // REVIEW: Do we even need this cast?

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* AuraOverlayWidgetController = GetOverlayWidgetController(WidgetControllerParams);

	AuraOverlayWidget->SetWidgetController(AuraOverlayWidgetController);
	AuraOverlayWidgetController->BroadcastInitialValues(); // This needs to happen after the OverlayWidgetController is set
	AuraOverlayWidget->AddToViewport();
	// Widget->AddToViewport();
}

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		CreateOverlayWidgetController(WCParams);
	}
	return OverlayWidgetController;
}

void AAuraHUD::CreateOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
	OverlayWidgetController->SetWidgetControllerParams(WCParams);
	OverlayWidgetController->BindCallbacksToDependencies();
}

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	if (AttributeMenuWidgetController == nullptr)
	{
		CreateAttributeMenuWidgetController(WCParams);
	}
	return AttributeMenuWidgetController;
}

void AAuraHUD::CreateAttributeMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this, AttributeMenuWidgetControllerClass);
	AttributeMenuWidgetController->SetWidgetControllerParams(WCParams);
	AttributeMenuWidgetController->BindCallbacksToDependencies();
}
