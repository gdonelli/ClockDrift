//
//  CDPeerTalkViewController.h
//  Clock Drift
//
//  Created by Giovanni Donelli on 11/10/13.
//  Copyright (c) 2013 Astro HQ LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PTChannel.h"

@interface CDPeerTalkViewController : UIViewController <PTChannelDelegate>
{
    __weak PTChannel *serverChannel_;
    __weak PTChannel *peerChannel_;
}

- (void)appendOutputMessage:(NSString*)message;
- (void)sendDeviceInfo;

@property (retain, nonatomic) IBOutlet UILabel *disconnectedLabel;
@property (retain, nonatomic) IBOutlet UILabel *connectedLabel;

@end
