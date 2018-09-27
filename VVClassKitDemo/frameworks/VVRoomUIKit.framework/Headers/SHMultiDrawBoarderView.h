
//  Created by Apple on 2017/11/23.
//  Copyright © 2017年 Apple. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "SHDrawBoarderTool.h"
#import "SHBoardDrawer.h"
@protocol SHMultiDrawBoarderViewDelegate <NSObject>

- (void)brawBoarderZoom:(CGFloat )zoom;

- (void)getPageIndex:(NSInteger)index;

- (void)getBoardPages:(NSInteger)page;
//保存竖屏
- (void)onReceiveDrawBoarderOri:(NSDictionary *)mes;

@end

typedef void(^draftInfoBlock)(NSInteger num, NSArray * linesInfo, NSArray * canceledLinesInfo);



@interface SHMultiDrawBoarderView : UIView<VVDrawBoardDelegate, SHBoardDrawerDelegate>
@property (nonatomic, strong)NSIndexPath *index;
@property (nonatomic, assign)NSInteger num;
@property (nonatomic, strong)NSArray * linesInfo;
@property (nonatomic, strong)NSArray * canceledLinesInfo;
@property (nonatomic, copy)draftInfoBlock draftInfoBlock;
@property (nonatomic, copy)UIView * toolV;

@property (nonatomic, strong)SHDrawBoarderTool * boarderTool;
@property (nonatomic, assign)id<SHMultiDrawBoarderViewDelegate>delegate;

@property(nonatomic,assign)NSInteger currentIndex;
@property(nonatomic,assign)NSInteger boardCount;  // 白板数量
@property(nonatomic,strong)UICollectionView *collectionView;

//远端绘图数据消息绘画
- (void)onReceiveDrawBoarderMes:(NSString *)mes;
//本地绘图数据消息绘画
- (void)locationDrawBoarderMes:(NSString *)mes;
//设置普通画板
- (void)setDrawBoardType:(NSString *)drawBoardType;
//多白板翻页
- (void)onReceiveDrawBoarderIndexMes:(NSString *)mes;
//白板数量
- (void)onReceiveDrawBoarderPagesMes:(NSString *)mes;
//白板横竖屏切换
- (void)onReceiveDrawBoarderOriMes:(NSString *)mes;
//设置多白板信息绘制画板
-(void)setMultiDrawingBoard:(NSDictionary *)drawboardDict
                WithIndex:(NSNumber *)currentIndex
                WithCount:(NSNumber *)drawboardCount;

@end
