//
//  NSStringAPI.h
//  VVRoom
//
//  Created by Apple on 2017/11/30.
//  Copyright © 2017年 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSStringAPI : NSObject

+ (instancetype)shareNSString;

- (NSString *)convertToJsonData:(NSDictionary *)dict;

- (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;

- (UIColor *)colorWithHexString:(NSString *)hexString;

- (NSString *)hexStringFromColor:(UIColor *)color;

- (NSString *)hexFromUIColor:(UIColor *)color;

- (NSString *)sendMessage:(NSString *)message;

- (NSString *)sendMessageHDbard:(NSMutableArray *)proint WihtcColor:(NSString *)color WithPenSize:(NSNumber*)pensize WihtPentype:(NSNumber *)pen;

- (NSString *)setPenArray:(NSMutableArray *)array WithColor:(NSString *)color WithPenSize:(NSNumber *)pensize WithPenType:(NSNumber *)pen;

- (NSString *)clearHDbard;

- (void)networkState;

- (UIImage *)image:(NSString *)name WithBundle:(NSString *)bundleName;

@end
