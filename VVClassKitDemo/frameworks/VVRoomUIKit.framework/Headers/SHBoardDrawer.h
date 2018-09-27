//
//  SHBoardDrawer.h
//  VVRoomUIKit
//
//  Created by 无线视通 on 2018/9/1.
//  Copyright © 2018年 Apple. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
@protocol SHBoardDrawerDelegate <NSObject>
- (void)paintingArray:(NSMutableArray *)paintingArray
            WihtColor:(UIColor *)color
          WithPenSize:(CGFloat )pensize
          WihtPentype:(NSNumber *)penType;
@end

@interface SHBoardDrawer : UIView
@property (nonatomic,assign)id<SHBoardDrawerDelegate>delegate;
@property (nonatomic, assign) CGFloat width;
/**
 *  撤销的线条数组
 */
@property (nonatomic, strong)NSMutableArray * canceledLines;
/**
 *  线条数组
 */
@property (nonatomic, strong)NSMutableArray * lines;
@property (nonatomic, strong)NSString * linType;
@property (nonatomic, copy)UIView * sizeView;
@property (nonatomic, copy)UIView * penTypeView;
@property (nonatomic, copy)UIView * colorImageView;

/**
 *  清屏
 */
- (void)clearScreen;

/**
 *  撤销
 */
- (void)undo;

/**
 *  恢复
 */
- (void)redo;

//绘制画板
-(void)setDrawingBoardPoint:(NSArray *)pointArray
                  WihtColor:(NSString *)coler
                WihtPenSize:(NSNumber *)pensize
                WithPenType:(int)pentype
              WihtWebheight:(NSNumber *)height
               WihtWebWidth:(NSNumber *)width
               WihtBordType:(NSString *)bordType;
//切换页面重绘本地存储数据绘画
-(void)locationBoardPoint:(NSArray *)pointArray
                WihtColor:(NSString *)coler
              WihtPenSize:(NSNumber *)pensize
              WithPenType:(int)pentype
            WihtWebheight:(NSNumber *)height
             WihtWebWidth:(NSNumber *)width;

//设置切换到课件的画板frame
- (void)setPaintFrame:(float)downs;
//设置只有画板的Frame
- (void)setDrawBoarderFrame;
//选择画笔大小
- (void)selectPenSize:(CGFloat)penSize;
//选择画笔颜色
- (void)selectPenColor:(UIColor *)penColor;
//选择画笔形状
- (void)selectPenType:(int)penType;
//橡皮
- (void)clearDrashBord;

@end

