//
//  PhotoSource.h
//  iNaturalist
//
//  Created by Ken-ichi Ueda on 2/22/12.
//  Copyright (c) 2012 iNaturalist. All rights reserved.
//

#import <Three20/Three20.h>

@interface PhotoSource : TTURLRequestModel <TTModel, TTPhotoSource>
@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) NSMutableArray *photos;

- (id)initWithPhotos:(NSArray *)photos title:(NSString *)title;
- (void)removePhoto:(id<TTPhoto>)photo;

@end
