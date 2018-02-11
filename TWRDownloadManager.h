//
//  TWRDownloadManager.h
//  DownloadManager
//
//  Created by Michelangelo Chasseur on 25/07/14.
//  Copyright (c) 2014 Touchware. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>
#import "TWRDownloadCallback.h"

@interface TWRDownloadManager : NSObject

@property (nonatomic, strong) void(^backgroundTransferCompletionHandler)(void);

+ (instancetype)sharedManager;

#pragma mark - Download with estimated time

- (void)downloadFileForURL:(NSString *)urlString
				  withName:(NSString *)fileName
		  inDirectoryNamed:(NSString *)directory
			 progressBlock:(TWRDownloadProgressBlock)progressBlock
			 remainingTime:(TWRDownloadRemainingTimeBlock)remainingTimeBlock
		   completionBlock:(TWRDownloadCompletionBlock)completionBlock
	  enableBackgroundMode:(BOOL)backgroundMode;

- (void)downloadFileForURL:(NSString *)urlString
		  inDirectoryNamed:(NSString *)directory
			 progressBlock:(TWRDownloadProgressBlock)progressBlock
			 remainingTime:(TWRDownloadRemainingTimeBlock)remainingTimeBlock
		   completionBlock:(TWRDownloadCompletionBlock)completionBlock
	  enableBackgroundMode:(BOOL)backgroundMode;

- (void)downloadFileForURL:(NSString *)urlString
			 progressBlock:(TWRDownloadProgressBlock)progressBlock
			 remainingTime:(TWRDownloadRemainingTimeBlock)remainingTimeBlock
		   completionBlock:(TWRDownloadCompletionBlock)completionBlock
	  enableBackgroundMode:(BOOL)backgroundMode;

#pragma mark - Download without estimated time

- (void)downloadFileForURL:(NSString *)urlString
				  withName:(NSString *)fileName
		  inDirectoryNamed:(NSString *)directory
			 progressBlock:(TWRDownloadProgressBlock)progressBlock
		   completionBlock:(TWRDownloadCompletionBlock)completionBlock
	  enableBackgroundMode:(BOOL)backgroundMode;

- (void)downloadFileForURL:(NSString *)urlString
		  inDirectoryNamed:(NSString *)directory
			 progressBlock:(TWRDownloadProgressBlock)progressBlock
		   completionBlock:(TWRDownloadCompletionBlock)completionBlock
	  enableBackgroundMode:(BOOL)backgroundMode;

- (void)downloadFileForURL:(NSString *)urlString
			 progressBlock:(TWRDownloadProgressBlock)progressBlock
		   completionBlock:(TWRDownloadCompletionBlock)completionBlock
	  enableBackgroundMode:(BOOL)backgroundMode;

#pragma mark - Other than download

- (void)cancelDownloadForUrl:(NSString *)fileIdentifier;

- (void)cancelAllDownloads;

/**
 *  This method helps checking which downloads are currently ongoing.
 *
 *  @return an NSArray of NSString with the URLs of the currently downloading files.
 */
- (NSArray *)currentDownloads;

#pragma mark - File Management

- (void)cleanDirectoryNamed:(NSString *)directory;

- (BOOL)isFileDownloadingForUrl:(NSString *)fileIdentifier;
- (BOOL)isFileDownloadingForUrl:(NSString *)url withProgressBlock:(TWRDownloadProgressBlock)block;
- (BOOL)isFileDownloadingForUrl:(NSString *)url withProgressBlock:(TWRDownloadProgressBlock)block completionBlock:(TWRDownloadCompletionBlock)completionBlock;

- (NSString *)localPathForFile:(NSString *)fileIdentifier;
- (NSString *)localPathForFile:(NSString *)fileIdentifier inDirectory:(NSString *)directoryName;

- (BOOL)fileExistsForUrl:(NSString *)urlString;
- (BOOL)fileExistsForUrl:(NSString *)urlString inDirectory:(NSString *)directoryName;
- (BOOL)fileExistsWithName:(NSString *)fileName;
- (BOOL)fileExistsWithName:(NSString *)fileName inDirectory:(NSString *)directoryName;

- (BOOL)deleteFileForUrl:(NSString *)urlString;
- (BOOL)deleteFileForUrl:(NSString *)urlString inDirectory:(NSString *)directoryName;
- (BOOL)deleteFileWithName:(NSString *)fileName;
- (BOOL)deleteFileWithName:(NSString *)fileName inDirectory:(NSString *)directoryName;


@end
