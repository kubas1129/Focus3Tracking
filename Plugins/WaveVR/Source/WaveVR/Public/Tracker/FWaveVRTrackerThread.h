// "WaveVR SDK
// © 2019 HTC Corporation. All Rights Reserved.
//
// Unless otherwise required by copyright law and practice,
// upon the execution of HTC SDK license agreement,
// HTC grants you access to and use of the WaveVR SDK(s).
// You shall fully comply with all of HTC’s SDK license agreement terms and
// conditions signed by you and all SDK and API requirements,
// specifications, and documentation provided by HTC to You."

#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "Containers/Queue.h"

#include "Tracker/WaveVRTrackerUtils.h"

class WAVEVR_API FWaveVRTrackerThread : public FRunnable
{
	/** Singleton instance, can access the thread any time via static accessor, if it is active! */
	static  FWaveVRTrackerThread* Runnable;

	/** Thread to run the worker FRunnable on */
	FRunnableThread* Thread;

	/** Stop this thread? Uses Thread Safe Counter */
	FThreadSafeCounter StopTaskCounter;

	enum Actions
	{
		None = 0,
		Activate,
		Deactivate,
	};

public:
	FWaveVRTrackerThread();
	virtual ~FWaveVRTrackerThread();

	// Begin FRunnable interface.
	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();
	// End FRunnable interface

	/** Makes sure this thread has stopped properly */
	void EnsureCompletion();


	//~~~ Starting and Stopping Thread ~~~


	/*
		Start the thread and the worker from static (easy access)!
		This code ensures only 1 Prime Number thread will be able to run at a time.
		This function returns a handle to the newly started instance.
	*/
	static FWaveVRTrackerThread* JoyInit();

	/** Shuts down the thread. Static so it can easily be called from outside the thread context */
	static void Shutdown();


	// ~~~ WaveVR related components ~~~
	void StartTracker()
	{
		qActions.Enqueue(Actions::Activate);
	}
	void StopTracker()
	{
		qActions.Enqueue(Actions::Deactivate);
	}
	bool IsTrackerAvailable()
	{
		return (trackerStatus == EWaveVRTrackerStatus::AVAILABLE);
	}
	EWaveVRTrackerStatus GetTrackerStatus()
	{
		return trackerStatus;
	}

private:
	FCriticalSection m_mutex;
	bool shutDownThread;

	bool getSupportedFeature = false;
	volatile EWaveVRTrackerStatus trackerStatus = EWaveVRTrackerStatus::NOT_START;

	Actions action = Actions::None;
	TQueue<Actions> qActions;
};
