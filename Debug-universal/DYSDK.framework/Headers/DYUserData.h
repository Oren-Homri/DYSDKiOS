//
//  DYIdentify.h
//  DYApi
//
//  Created by Idan Oshri on 1/6/15.
//  Copyright (c) 2015 Dynamic Yield. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 * @header DYIdentify.h
 * @discussion A helper class to identify the user
 *
 */

@interface DYUserData : NSObject


/*!
 *  Allocate and init a new instance
 *
 *  @return DYIdentify instance
 */

+(DYUserData*)create;

/*!
 *  @brief The user's Email
 */
@property (strong,atomic) NSString* email;

/*!
 * @brief The user's first name
 */

@property (strong,atomic) NSString* firstName;

/*!
 * @brief The user's last name
 */

@property (strong,atomic) NSString* lastName;

/*!
 * @brief The user's age
 */

@property (strong,atomic) NSString* age;

/*!
 * @brief The user's gender
 */

@property (strong,atomic) NSString* gender;

/*!
 * @brief user identifier
 */

@property (strong,atomic) NSString* externalUserID;


@end
