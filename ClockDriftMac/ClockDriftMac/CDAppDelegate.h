//
//  CDAppDelegate.h
//  ClockDriftMac
//
//  Created by Giovanni Donelli on 11/10/13.
//  Copyright (c) 2013 Astro HQ LLC. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "PTChannel.h"
#import "PTUSBHub.h"
#import "PTExampleProtocol.h"
#import <QuartzCore/QuartzCore.h>

static const NSTimeInterval PTAppReconnectDelay = 1.0;

@interface CDAppDelegate : NSObject <NSApplicationDelegate>
{
    NSNumber *connectingToDeviceID_;
    NSNumber *connectedDeviceID_;
    NSDictionary *connectedDeviceProperties_;
    NSDictionary *remoteDeviceInfo_;
    dispatch_queue_t notConnectedQueue_;
    BOOL notConnectedQueueSuspended_;
    PTChannel *connectedChannel_;
    NSDictionary *consoleTextAttributes_;
    NSDictionary *consoleStatusTextAttributes_;
    NSMutableDictionary *pings_;
}

@property (assign) IBOutlet NSWindow *window;

- (IBAction)sendMessage:(id)sender;

@property (readonly) NSNumber *connectedDeviceID;
@property PTChannel *connectedChannel;

- (void)presentMessage:(NSString*)message isStatus:(BOOL)isStatus;
- (void)startListeningForDevices;
- (void)didDisconnectFromDevice:(NSNumber*)deviceID;
- (void)disconnectFromCurrentChannel;
- (void)enqueueConnectToLocalIPv4Port;
- (void)connectToLocalIPv4Port;
- (void)connectToUSBDevice;
- (void)ping;


@end
