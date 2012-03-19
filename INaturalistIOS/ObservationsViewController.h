//
//  ObservationsViewController.h
//  iNaturalist
//
//  Created by Ken-ichi Ueda on 2/13/12.
//  Copyright (c) 2012 iNaturalist. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ObservationDetailViewController.h"
#import "LoginViewController.h"

@class Observation;
@class ObservationStore;
@class DejalActivityView;

@interface ObservationsViewController : UITableViewController <ObservationDetailViewControllerDelegate, RKObjectLoaderDelegate, LoginViewControllerDelegate, RKRequestQueueDelegate, UIAlertViewDelegate>
{
    DejalActivityView *syncActivityView;
}
@property (nonatomic, strong) NSMutableArray *observations;
@property (nonatomic, assign) int observationsToSyncCount;
@property (nonatomic, assign) int syncedObservationsCount;
@property (nonatomic, assign) int observationPhotosToSyncCount;
@property (nonatomic, assign) int syncedObservationPhotosCount;
@property (nonatomic, strong) NSArray *syncToolbarItems;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *syncButton; // if the button is just kind of floating and not assigned a super view, it will get deallocated UNLESS we have a strong reference here
@property (nonatomic, strong) UIBarButtonItem *deleteAllButton;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *editButton;
@property (strong, nonatomic) UIBarButtonItem *stopSyncButton;
@property (nonatomic, strong) RKObjectLoader *loader;
@property (nonatomic, strong) UILabel *noContentLabel;

- (IBAction)sync:(id)sender;
- (void)stopSync;
- (IBAction)edit:(id)sender;
- (void)stopEditing;

- (void)syncObservations;
- (void)syncObservationPhotos;
- (void)loadData;
- (void)reload;
- (void)checkSyncStatus;
- (int)itemsToSyncCount;
- (void)clickedDeleteAll;
- (void)deleteAll;
- (void)handleNSManagedObjectContextDidSaveNotification:(NSNotification *)notification;
- (BOOL)isSyncing;
@end
