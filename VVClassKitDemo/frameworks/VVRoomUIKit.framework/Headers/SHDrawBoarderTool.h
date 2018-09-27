//  Created by Apple on 2017/11/23.
//  Copyright © 2017年 Apple. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
@protocol SHDrawBoarderToolDelegate <NSObject>
//选择画笔大小
- (void)selectPenSize:(CGFloat)penSize;
//选择画笔颜色
- (void)selectPenColor:(UIColor *)penColor;
//选择画笔形状
- (void)selectPenType:(int)penType;
//选择橡皮擦
- (void)selectEraser;
//清除画板
- (void)clearDrawBoarder;

@end

@interface SHDrawBoarderTool : UIView

@property (nonatomic,assign)id<SHDrawBoarderToolDelegate>delegate;

- (instancetype)initWithFrame:(CGRect)frame;
//显示、隐藏工具栏
- (void)hideDrawBoardTool:(BOOL)hied;

@end
