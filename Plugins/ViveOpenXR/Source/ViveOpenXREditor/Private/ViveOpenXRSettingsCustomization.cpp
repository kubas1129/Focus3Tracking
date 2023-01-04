// Copyright (c) 2022 HTC Corporation. All Rights Reserved.


#include "ViveOpenXRSettingsCustomization.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Text/SRichTextBlock.h"
#include "Widgets/Input/SButton.h"
#include "DetailWidgetRow.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "Misc/Paths.h"

#define LOCTEXT_NAMESPACE "OpenXRViveSettings"
TSharedRef<IDetailCustomization> FViveOpenXRSettingsCustomization::MakeInstance()
{
	return MakeShareable(new FViveOpenXRSettingsCustomization);
}

void FViveOpenXRSettingsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	//IDetailCategoryBuilder& CosmosControllerCategory = DetailLayout.EditCategory(TEXT("Controller"));
	//IDetailCategoryBuilder& Focus3ControllerCategory = DetailLayout.EditCategory(TEXT("Controller"));
	//IDetailCategoryBuilder& FacialTrackingCategory = DetailLayout.EditCategory(TEXT("Facial Tracking"));
	//IDetailCategoryBuilder& SceneUnderstandingCategory = DetailLayout.EditCategory(TEXT("Scene Understanding"));

	//CosmosControllerCategory.AddCustomRow(LOCTEXT("CosmosControllerUsageInfo", "Cosmos Controller Usage Info"), false)
	//	.WholeRowWidget
	//	[
	//		SNew(SBorder)
	//		.Padding(1)
	//		[
	//			SNew(SHorizontalBox)
	//			+ SHorizontalBox::Slot()
	//			.Padding(FMargin(10, 10, 10, 10))
	//			.FillWidth(1.0f)
	//			[
	//				SNew(SRichTextBlock)
	//				.Text(LOCTEXT("CosmosControllerUsageInfoMessage", "The OpenXR extension <RichTextBlock.TextHighlight>XR_HTC_vive_cosmos_controller_interaction</> enables the use of HTC Vive Cosmos Controllers interaction profiles in OpenXR. \n \"Enable Cosmos Controller\" setting will enable OpenXR Cosmos Controller extension. \n <RichTextBlock.TextHighlight>NOTE:</> You need to restart the engine to apply new settings after clicking \"Enable Cosmos Controller\"."))
	//				.TextStyle(FEditorStyle::Get(), "MessageLog")
	//				.DecoratorStyleSet(&FEditorStyle::Get())
	//				.AutoWrapText(true)
	//			]
	//		]
	//	];

	//Focus3ControllerCategory.AddCustomRow(LOCTEXT("Focus3ControllerUsageInfo", "Focus3 Controller Usage Info"), false)
	//	.WholeRowWidget
	//	[
	//		SNew(SBorder)
	//		.Padding(1)
	//		[
	//			SNew(SHorizontalBox)
	//			+ SHorizontalBox::Slot()
	//			.Padding(FMargin(10, 10, 10, 10))
	//			.FillWidth(1.0f)
	//			[
	//				SNew(SRichTextBlock)
	//				.Text(LOCTEXT("Focus3ControllerUsageInfoMessage", "The OpenXR extension <RichTextBlock.TextHighlight>XR_HTC_vive_focus3_controller_interaction</> enables the use of HTC Vive Focus3 Controllers interaction profiles in OpenXR. \n \"Enable Focus3 Controller\" setting will enable OpenXR Focus3 Controller extension. \n <RichTextBlock.TextHighlight>NOTE:</> You need to restart the engine to apply new settings after clicking \"Enable Focus3 Controller\"."))
	//				.TextStyle(FEditorStyle::Get(), "MessageLog")
	//				.DecoratorStyleSet(&FEditorStyle::Get())
	//				.AutoWrapText(true)
	//			]
	//		]
	//	];

	//FacialTrackingCategory.AddCustomRow(LOCTEXT("FacialTrackingUsageInfo", "Facial Tracking Info"), false)
	//	.WholeRowWidget
	//	[
	//		SNew(SBorder)
	//		.Padding(1)
	//		[
	//			SNew(SHorizontalBox)
	//			+ SHorizontalBox::Slot()
	//			.Padding(FMargin(10, 10, 10, 10))
	//			.FillWidth(1.0f)
	//			[
	//				SNew(SRichTextBlock)
	//				.Text(LOCTEXT("FacialTrackingUsageInfoMessage", "To help software developers create an application with actual facial expressions on 3D avatars with the OpenXR facial tracing extension <RichTextBlock.TextHighlight>XR_HTC_facial_tracking</>. \n \"Enable Facial Tracking\" setting will enable OpenXR Facial Tracking extension. \n <RichTextBlock.TextHighlight>NOTE:</> You need to restart the engine to apply new settings after clicking \"Enable Facial Tracking\"."))
	//				.TextStyle(FEditorStyle::Get(), "MessageLog")
	//				.DecoratorStyleSet(&FEditorStyle::Get())
	//				.AutoWrapText(true)
	//			]
	//		]
	//	];

	//SceneUnderstandingCategory.AddCustomRow(LOCTEXT("SceneUnderstandingUsageInfo", "Scene Understanding Info"), false)
	//	.WholeRowWidget
	//	[
	//		SNew(SBorder)
	//		.Padding(1)
	//		[
	//			SNew(SHorizontalBox)
	//			+ SHorizontalBox::Slot()
	//			.Padding(FMargin(10, 10, 10, 10))
	//			.FillWidth(1.0f)
	//			[
	//				SNew(SRichTextBlock)
	//				.Text(LOCTEXT("SceneUnderstandingUsageInfoMessage", "Demonstrate configuring, calculating and generating mesh of surrouding environments by the OpenXR scene understanding extension <RichTextBlock.TextHighlight>XR_MSFT_scene_understanding</>. \n \"Enable Scene Understanding\" setting will enable OpenXR Scene Understanding extension. \n <RichTextBlock.TextHighlight>NOTE:</> You need to restart the engine to apply new settings after clicking \"Enable Scene Understanding\"."))
	//				.TextStyle(FEditorStyle::Get(), "MessageLog")
	//				.DecoratorStyleSet(&FEditorStyle::Get())
	//				.AutoWrapText(true)
	//			]
	//		]
	//	];
}

FViveOpenXRSettingsCustomization::FViveOpenXRSettingsCustomization()
{
}
