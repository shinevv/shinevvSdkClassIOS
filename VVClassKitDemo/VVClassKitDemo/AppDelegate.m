//
//  AppDelegate.m
//  VVRoom
//
//  Created by Apple on 2017/11/23.
//  Copyright © 2017年 Apple. All rights reserved.
//

#import "AppDelegate.h"
#import <VVClassKit/VVClassKit.h>


@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.loginVC = [[VVLogInControlle alloc] init];
    [[VVClassManager shareManager] launchingWithWindow:self.window loginvc:self.loginVC];
    [self.window makeKeyAndVisible];
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    
    UIApplication *applications = [UIApplication sharedApplication];
    [applications setKeepAliveTimeout:600 handler:^{
        [[VVClassManager shareManager] reConnect];
    }];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.

}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}
//通过URL-Schemes调用app ios9以下
- (BOOL)application:(UIApplication *)application
            openURL:(nonnull NSURL *)url
            options:(nonnull NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options{
    
    return YES;
}

//通过universal-Link调用app ios9以上
- (BOOL)application:(UIApplication *)application
        continueUserActivity:(NSUserActivity *)userActivity
        restorationHandler:(void (^)(NSArray *restorableObjects))
        restorationHandler{
   
    if ([userActivity.activityType isEqualToString:NSUserActivityTypeBrowsingWeb]) {
        
        NSURL * webpageURL = userActivity.webpageURL;
        NSString * webUrlStr = webpageURL.absoluteString;
        NSMutableDictionary * StringDictionary = [[NSMutableDictionary alloc] init];
        NSArray *urlComponents = [webUrlStr componentsSeparatedByString:@"&"];
        
        for (NSString *keyValuePair in urlComponents){
            NSArray *pairComponents = [keyValuePair componentsSeparatedByString:@"="];
            NSString *key = [[pairComponents firstObject] stringByRemovingPercentEncoding];
            NSString *value = [[pairComponents lastObject] stringByRemovingPercentEncoding];
            [StringDictionary setObject:value forKey:key];
        }
        
        if (StringDictionary) {
            self.loginVC.nikeTestFiled.text =
            [StringDictionary objectForKey:@"nick_name"];
            self.loginVC.accountTextFiled.text =
            [StringDictionary objectForKey:@"room_number"];
            self.loginVC.passwordTextFiled.text =
            [StringDictionary objectForKey:@"room_password"];
        }
    }
    return YES;
}

@end
