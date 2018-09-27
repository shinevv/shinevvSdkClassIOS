
//  Created by Apple on 2017/11/23.
//  Copyright © 2017年 Apple. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "SHDrawBoarderTool.h"
#import "SHDrawer.h"
@protocol SHDrawBoarderViewDelegate <NSObject>

- (void)brawBoarderZoom:(CGFloat )zoom;

@end

typedef void(^draftInfoBlock)(NSInteger num, NSArray * linesInfo, NSArray * canceledLinesInfo);

/**
 画笔类型
 */
typedef NS_ENUM (int, pen)   {
    pencilPen = 1,//铅笔
    brushPen,     //画笔
    linePen,      //直线
    ArrowPen,     //箭头
    squarePen,    //方形
    circularPen,  //圆形
    Eraser = 10,  //橡皮擦
};

/**
 画布操作
 */
typedef NS_ENUM(int,operationType){
    ACTION_PEN = 1,//
    ACTION_ERASE,  //撤销
    ACTION_CLEAR,  //清空
};

@interface SHDrawBoarderView : UIView<VVDrawBoardDelegate>
@property (nonatomic, strong)NSIndexPath *index;
@property (nonatomic, assign)NSInteger num;
@property (nonatomic, strong)NSArray * linesInfo;
@property (nonatomic, strong)NSArray * canceledLinesInfo;
@property (nonatomic, copy)draftInfoBlock draftInfoBlock;
@property (nonatomic, copy)UIView * toolV;
@property (nonatomic, strong)SHDrawer * myDrawer;
@property (nonatomic, strong)SHDrawBoarderTool * boarderTool;
@property (nonatomic, assign)id<SHDrawBoarderViewDelegate>delegate;

//远端绘图数据消息绘画
- (void)onReceiveDrawBoarderMes:(NSString *)mes;
//本地绘图数据消息绘画
- (void)locationDrawBoarderMes:(NSString *)mes;
//设置普通画板
- (void)setDrawBoardType:(NSString *)drawBoardType;

- (NSString*)getType;

@end
