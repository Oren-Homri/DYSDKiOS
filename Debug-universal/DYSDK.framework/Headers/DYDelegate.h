//
//  DYDelegate.h
//  DYApi
//
//  Created by Idan Oshri on 2/24/15.
//  Copyright (c) 2015 Dynamic Yield. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum {
    DY_NOT_INITIALIZED,
    DY_INIT_CALLED,
    DY_SECTION_INACTIVE,
    DY_INIT_FAILED,
    DY_INIT_OK
    
} InitReply;

/*!
 * @header DYDelegateProtocol.h
 * @discussion Dynamic Yield API's Delegate Object
 *
 */


@protocol DYDelegateProtocol <NSObject>

@optional

/*!
 *  Called after the server responded the init request
 *
 *  @param initStatus - the server result
 */
-(void)onInitReply:(InitReply)initStatus;


/*!
 *  Called when the experiments has been updated and ready to use
 */

-(void)experimentsUpdatedAndReady;

/*!
 *  Called with the result of running a smart object experiments
 *
 *  @param smartObjID the smart object ID
 *  @param html       the HTML that returned (may be null)
 *  @param webView    the webview
 */

-(void)smartObject:(NSString*)smartObjID returned:(NSString*)html on:(UIWebView*)webView;

/*!
 *  This method is called after an Overlay or Custom Action has been triggered and a variation has
 * been selected by Dynamic Yield.  For Custom Actions the implementation of the method should
 * include the desired app manipulation based on the JSON data returned.  For Overlays where
 * ‘shouldDYRender’ was set to ‘false’, this method allows manipulation and 
 * custom rendering 8 based on the HTML data returned by Dynamic Yield.
 
 *  @param smartActionID - The Smart Action ID as maintained in the Dynamic Yield Admin Console
 *  @param smartActionData - The variation data as maintained in the Dynamic Yield Admin Console;
 * this can be either the Messaging Overlay HTML or the Custom Action JSON.
 */

-(void)onSmartAction:(NSString*)smartActionID returned:(NSDictionary*)smartActionData;

/*!
 *  This method is called just before the HTML Overlay content is rendered
 *  by Dynamic Yield and allows preventing its rendering.  The default value is ‘true’.
 *
 *  @param smartActionID - The Smart Action ID as maintained in the Dynamic Yield Admin Console
 */
 
-(BOOL)shouldDYRender:(NSString*)smartActionID;


@end



@protocol DYRecommendationsDelegate <NSObject>


/*!
 *  A delegate method called with the return of the recommendation results. This is where the rendering logic of the returned recommended items should take place. 
 *  The input parameter is an array of JSON objects, each item in the returned array includes the available metadata for every recommendation item.
 *
 *  @param recommendations - recommendations results from the server
 */
-(void)onRecommendationResult:(NSArray*)recommendations;

@end
