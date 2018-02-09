//
//  TWRDownloadCallback.h
//  DownloadManager
//
//  Created by John on 2018-2-9.
//  Copyright © 2018 Touchware. All rights reserved.
//

typedef void(^TWRDownloadRemainingTimeBlock)(NSUInteger seconds);
typedef void(^TWRDownloadProgressBlock)(CGFloat progress);
typedef void(^TWRDownloadCompletionBlock)(BOOL completed);
