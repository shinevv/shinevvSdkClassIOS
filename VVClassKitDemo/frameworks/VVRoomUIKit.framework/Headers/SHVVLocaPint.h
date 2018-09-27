//  Created by Apple on 2017/11/23.
//  Copyright © 2017年 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface SHVVLocaPint : NSObject
+ (instancetype)shareLocaPint;
//添加本对应地画板绘画记录
- (void)addLocaStr:(NSString *)locaStr WithPath:(NSString *)path;
//获取本地绘画历史记录
- (NSMutableArray *)getLocaStrArray;
//删除本地画板记录
- (void)remLocaStr:(NSString *)boarderId;
//删除本地画板缓存
- (void)remLocaPath;
//添加同步历史记录数据
- (void)addhistyStr:(NSString *)str;
//获取历史立即
- (NSMutableArray *)gethistyStr;
//存储图片缩放后的真实大小
- (void)setImageScanSize:(CGRect)scanSize;
//获取不同画板size
- (CGRect)getImageScanSize;

- (void)sethistyDict:(NSDictionary *)dictData;
- (NSDictionary *)gethistyData;

@end
