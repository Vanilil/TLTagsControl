//
//  TLTagsControl.h
//  TagsInputSample
//
//  Created by Антон Кузнецов on 11.02.15.
//  Copyright (c) 2015 TheLightPrjg. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TLTagsControl;

@protocol TLTagsControlDelegate <NSObject>

- (void)tagsControl:(TLTagsControl *)tagsControl tappedAtIndex:(NSInteger)index;
- (void) actionToChooseTags:(TLTagsControl *)tagsControl;
- (void)tagsControl:(TLTagsControl *)tagsControl removedAtIndex:(NSInteger)index;

@end

typedef NS_ENUM(NSUInteger, TLTagsControlMode) {
    TLTagsControlModeEdit,
    TLTagsControlModeList,
};

IB_DESIGNABLE @interface TLTagsControl : UIScrollView

@property (nonatomic, strong) NSMutableArray *tags;
@property (nonatomic, strong) IBInspectable UIColor *viewBackgroundColor;
@property (nonatomic, strong) IBInspectable UIColor *tagsBackgroundColor;
@property (nonatomic, strong) IBInspectable UIColor *tagsTextColor;
@property (nonatomic, strong) IBInspectable UIColor *tagsDeleteButtonColor;
@property (nonatomic, strong) IBInspectable UIColor *tagsBorderColor;
@property (nonatomic) IBInspectable CGFloat tagsBordersize;
@property (nonatomic, strong) IBInspectable NSString *tagPlaceholder;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic) TLTagsControlMode mode;
@property (nonatomic) IBInspectable CGFloat marginTags;
@property (nonatomic) IBInspectable CGFloat tagsCornerRadius;
@property (nonatomic) IBInspectable BOOL chooseTaggWithClic;

@property (assign, nonatomic) id<TLTagsControlDelegate> tapDelegate;

- (id)initWithFrame:(CGRect)frame andTags:(NSArray *)tags withTagsControlMode:(TLTagsControlMode)mode;

- (void)addTag:(NSString *)tag;
- (void)reloadTagSubviews;
- (void)setKeyboardFocus;

@end
