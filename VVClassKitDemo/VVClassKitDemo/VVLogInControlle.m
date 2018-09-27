//
//  VVLogInControlle.m
//  VVRoom
//
//  Created by Apple on 2017/11/23.
//  Copyright © 2017年 Apple. All rights reserved.
//

#import "VVLogInControlle.h"
#import <VVClassKit/VVClassKit.h>
//#import "VVRootViewController.h"
//#import "AppDelegate.h"
//#import "MMDrawerController.h"
@interface VVLogInControlle ()
{
//    VVRootViewController * rootVc;
//    MMDrawerController * drawerController;
}
@end

@implementation VVLogInControlle

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationController.navigationBar.barStyle = UIBarStyleBlack;
    _accountNameLab.layer.cornerRadius = 23;
    _accountNameLab.layer.masksToBounds = YES;
    _passwordLav.layer.cornerRadius = 23;
    _passwordLav.layer.masksToBounds = YES;
    [_accountTextFiled setTextColor:[UIColor whiteColor]];
    [_passwordTextFiled setTextColor:[UIColor whiteColor]];
    
    _nikeNameLab.layer.cornerRadius = 23;
    _nikeNameLab.layer.masksToBounds = YES;
    [_nikeTestFiled setTextColor:[UIColor whiteColor]];
    
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    NSString *appCurVersionNum = [infoDictionary objectForKey:@"CFBundleShortVersionString"];
    _versionLab.text = [NSString stringWithFormat:@"亮眼课堂%@",appCurVersionNum];
    
//    if ([[SHvvUserInforManager defaultUserInfo]getNickName].length > 0) {
//        _accountTextFiled.text = [[SHvvUserInforManager defaultUserInfo] getRoomId];
//        _nikeTestFiled.text = [[SHvvUserInforManager defaultUserInfo] getNickName];
//    }
    
    bool isDebug = false;
    if (isDebug) {
        _accountTextFiled.text = @"50204";
        _passwordTextFiled.text = @"222222";
        _nikeTestFiled.text = @"ios";
    }
}
//login
- (IBAction)loginClick:(id)sender {

    [[VVClassManager shareManager] loginWithAccont:_accountTextFiled.text password:_passwordTextFiled.text nick:_nikeTestFiled.text];
//    if ([self accountAndPassword:_accountTextFiled.text] == YES &&
//        [self accountAndPassword:_passwordTextFiled.text] == YES && _nikeTestFiled.text.length > 0){
//
//        if ([_accountTextFiled.text containsString:@" "]) {
//            [SHAlertView showAlertWithMessage:NSLocalizedString(@"spaceClass", nil) autoDisappearAfterDelay:1];
//        }else{
//            [MBProgressHUD showHUDAddedTo:self.view animated:YES];
//
//
//            NSDictionary * userDict = @{@"room_id":_accountTextFiled.text,@"password":_passwordTextFiled.text};
//
//            [[VVRoomNet shareNet]postAFN:[VVRoomAPI VVlogin] andpara:userDict andBlock:^(id result, NSURLSessionDataTask *operation) {
//
//                if ([[NSString stringWithFormat:@"%@",[result objectForKey:@"code"]] isEqualToString:@"0"]) {
//                    NSDictionary * dataDict = [result objectForKey:@"data"];
//                    NSString * roleStr = [dataDict objectForKey:@"role"];
//                    //老师、助教
//                    if ([roleStr isEqualToString:@"teacher"]) {
//                        [SHAlertView showAlertWithMessage:NSLocalizedString(@"doNoteacherLogin", nil) autoDisappearAfterDelay:1];
//                    }else if ([roleStr isEqualToString:@"tutor"]){
//                        [SHAlertView showAlertWithMessage:NSLocalizedString(@"doNoAssistantLogin", nil) autoDisappearAfterDelay:1];
//                    }else{
//                    //学生、旁听、巡课
//                        [[SHvvUserInforManager defaultUserInfo] initWithTitle:[dataDict objectForKey:@"title"]
//                                                                WithUserToken:[dataDict objectForKey:@"token"]
//                                                                   WithRoomId:_accountTextFiled.text
//                                                                     WithRole:[dataDict objectForKey:@"role"]
//                                                                 WithNickName:_nikeTestFiled.text];
//
//                        NSDictionary * wsDict = [dataDict objectForKey:@"wss"];
//                        if(wsDict && wsDict.count!=0){
//                            NSString* wsDomain = [wsDict objectForKey:@"server"];
//                            NSInteger wsPort = [[wsDict objectForKey:@"port"] integerValue];
//                            [[SHvvUserInforManager defaultUserInfo] setWsDomain:wsDomain withPort:wsPort];
//                        }
//                        AppDelegate *appDelegate = (AppDelegate *)[[UIApplication sharedApplication] delegate];
//                        [appDelegate setRootVC];
//                    }
//                    [MBProgressHUD hideHUDForView:self.view animated:YES];
//
//                }else{
//                    [MBProgressHUD hideHUDForView:self.view animated:YES];
//                    [SHAlertView showAlertWithMessage:[NSString stringWithFormat:@"%@",[result objectForKey:@"message"]] autoDisappearAfterDelay:1];
//                };
//
//            } andfailBlock:^(id fail, NSURLSessionDataTask *operation) {
//                [MBProgressHUD hideHUDForView:self.view animated:YES];
//                [SHAlertView showAlertWithMessage:NSLocalizedString(@"onCheakNetWork", nil) autoDisappearAfterDelay:1];
//            }];
//
//        }
//    }else{
//
//        if ( _nikeTestFiled.text.length <= 0) {
//            [SHAlertView showAlertWithMessage:NSLocalizedString(@"nikeNameSpace", nil) autoDisappearAfterDelay:1];
//        }
//        if ( _passwordTextFiled.text.length <= 0) {
//            [SHAlertView showAlertWithMessage:NSLocalizedString(@"passWordSpace", nil) autoDisappearAfterDelay:1];
//        }
//        if ( _accountTextFiled.text.length <= 0) {
//            [SHAlertView showAlertWithMessage:NSLocalizedString(@"classNumberSpace", nil) autoDisappearAfterDelay:1];
//        }
//        [MBProgressHUD hideHUDForView:self.view animated:YES];
//
//    }
    
}

//- (BOOL)accountAndPassword:(NSString *)str{
//
//    if ([str isKindOfClass:[NSNull class]] || [str isEqualToString:@""] || str == nil) {
//        return NO;
//    }else{
//        return YES;
//    }
//}

@end
