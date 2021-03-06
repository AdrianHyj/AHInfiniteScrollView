//
//  AHInfiniteScrollView.h
//  CalendarDemo
//
//  Created by Jin on 21/9/17.
//  Copyright © 2017年 Jin. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AHInfiniteScrollView;

@protocol AHInfiniteScrollViewDelegate <NSObject>

@optional
- (void)infiniteScrollViewDidScrollToNextRound:(AHInfiniteScrollView *)scrollview;
- (void)infiniteScrollViewDidScrollToPreRound:(AHInfiniteScrollView *)scrollview;

@end

/**
 无限循环ScrollView
 */
@interface AHInfiniteScrollView : UIScrollView

@property (nonatomic, weak) id<AHInfiniteScrollViewDelegate> infiniteScrollDelegate;

/**
 初始化无线循环Scrollview
 如果views加起来的宽度都不够 scrollview*2 的宽度的话，控件会不可拖动。

 @param views           需要循环展示的View
 @param frame           scrollview的frame
 @param seprateWidth    views之间的间隔
 @return 实例
 */
- (instancetype)initWithViews:(NSArray *)views frame:(CGRect)frame seprateWidth:(CGFloat)seprateWidth;

/**
 *设置需要循环展示的View
 *如果views加起来的宽度都不够 scrollview*2 的宽度的话，控件会不可拖动。
 
 @param views 需要循环展示的View
 @param seprateWidth views之间的间隔
 */
- (void)resetPresentViews:(NSArray *)views seprateWidth:(CGFloat)seprateWidth;

/**
 把view滚动到中间
 如果不存在view，则不做任何事
 如果在滚动中，则不做任何事

 @param view 需要滚动到中间的view（如果不存在，则不做任何事）
 */
- (void)scrollViewToMiddle:(UIView *)view;

@end
