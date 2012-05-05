//
//  ABSViewController.h
//  AppboySample
//
//  Created by Jonathan Hyman on 5/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ABSViewController : UIViewController {
  IBOutlet UIButton *appboyButton;
  IBOutlet UIButton *shareButton;
}
@property (nonatomic, retain) UIButton *appboyButton;
@property (nonatomic, retain) UIButton *shareButton;
@end