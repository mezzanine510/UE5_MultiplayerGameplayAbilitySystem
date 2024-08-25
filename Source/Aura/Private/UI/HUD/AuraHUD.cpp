// Copyright Monkeyman Studios


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"


UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (WidgetController == nullptr)
	{
		WidgetController = NewObject<UOverlayWidgetController>(this, WidgetControllerClass);
		WidgetController->SetWidgetControllerParams(WCParams);
		return WidgetController;
	}

	return WidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is not set in BP_AuraHUD"));
	checkf(WidgetControllerClass, TEXT("OverlayWidgetControllerClass is not set in BP_AuraHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* OverlayWidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(OverlayWidgetController);
	
	OverlayWidget->AddToViewport();
}
