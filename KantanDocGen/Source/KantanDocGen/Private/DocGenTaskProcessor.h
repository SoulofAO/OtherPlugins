// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

// Copyright (C) 2016-2017 Cameron Angus. All Rights Reserved.

#pragma once

#include "DocGenSettings.h"

#include "HAL/Runnable.h"
#include "HAL/ThreadSafeBool.h"
#include "UObject/WeakObjectPtrTemplates.h"
#include "Containers/Queue.h"
#include "CoreMinimal.h"


class ISourceObjectEnumerator;
class FNodeDocsGenerator;

class UBlueprintNodeSpawner;


class FDocGenTaskProcessor: public FRunnable
{
public:
	FDocGenTaskProcessor();

public:
	void QueueTask(FKantanDocGenSettings const& Settings);
	bool IsRunning() const;

public:
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Exit() override;
	virtual void Stop() override;

protected:
	struct FDocGenTask
	{
		FKantanDocGenSettings Settings;
		TSharedPtr< class SNotificationItem > Notification;
	};

	struct FDocGenCurrentTask
	{
		TSharedPtr< FDocGenTask > Task;

		TQueue< TSharedPtr< ISourceObjectEnumerator > > Enumerators;
		TSet< FName > Excluded;
		TSet< TWeakObjectPtr< UObject > > Processed;

		TSharedPtr< ISourceObjectEnumerator > CurrentEnumerator;
		TWeakObjectPtr< UObject > SourceObject;
		TQueue< TWeakObjectPtr< UBlueprintNodeSpawner > > CurrentSpawners;

		TUniquePtr< FNodeDocsGenerator > DocGen;
	};

	struct FDocGenOutputTask
	{
		TSharedPtr< FDocGenTask > Task;
	};

protected:
	void ProcessTask(TSharedPtr< FDocGenTask > InTask);

	enum EIntermediateProcessingResult: uint8 {
		Success,
		SuccessWithErrors,
		UnknownError,
		DiskWriteFailure,
	};

	EIntermediateProcessingResult ProcessIntermediateDocs(FString const& IntermediateDir, FString const& OutputDir, FString const& DocTitle, bool bCleanOutput);

protected:
	TQueue< TSharedPtr< FDocGenTask > > Waiting;
	TUniquePtr< FDocGenCurrentTask > Current;
	TQueue< TSharedPtr< FDocGenOutputTask > > Converting;

	FThreadSafeBool bRunning;	// @NOTE: Using this to sync with module calls from game thread is not 100% okay (we're not atomically testing), but whatevs.
	FThreadSafeBool bTerminationRequest;
};


