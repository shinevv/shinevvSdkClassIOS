//
//  VVClassManager.h
//  VVClassKit
//
//  Created by 无线视通 on 2018/9/25.
//  Copyright © 2018年 无线视通. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface VVClassManager : NSObject
@property (nonatomic, strong)UIViewController* loginVC;
@property (nonatomic, strong)UIWindow* window;
+ (instancetype)shareManager;


//- (void)setRootOfWindow:(UIWindow*)win;
//- (void)enableGesture:(BOOL)bEnable;
- (void)launchingWithWindow:(UIWindow*) win loginvc:(UIViewController*)loginVC;
- (void)reConnect;
- (void)loginWithAccont:(NSString*)acc password:(NSString*)pass nick:(NSString*)name;
@end
