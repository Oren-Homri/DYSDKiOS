//
//  DYApi.h
//  DYApi
//
//  Created by Idan Oshri on 14/D/14.
//  Copyright (c) 2014 Dynamic Yield. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DYUserData.h"
#import "DYDelegate.h"
#import <UIKit/UIKit.h>
#import "DYPageContext.h"

/*!
 * @header DYApi.h
 * @discussion Dynamic Yield API
 *
 */

@interface DYApi : NSObject

/*!
 *  Main method, gets the shared instance of the SDK
 *
 *  @return DYApi shared instance
 */
+(DYApi*)getInstance ;

/*!
 *  Set an delegate object to receive notifications from DYApi
 *
 *  @param delegate - The delegate object
 *
 *  @return Yes if the object is OK
 */
-(BOOL)setDelegate:(id<DYDelegateProtocol>)delegate;

/*!
 *  Sets the identifier in order to log the data
 *
 *  @param secret - String key, can be created in the Admin screen
 *
 *  @return Yes if the secret is not nil or empty
 */
-(BOOL)setSecretKey:(NSString*)secret;


-(BOOL)setPushNotificationID:(NSData*)pushID;

/*!
 *  Help identify the user in a cross platform world
 *
 *  @param userAttributes - DYIdentify type,
 *  Holds the basic identifiers
 *
 *  @return Yes if the identifiers is not nil or empty
 */
-(BOOL)identifyUser:(DYUserData*)userAttributes;

/*!
 *  Sends an event to the database.
 *
 *  @param name  -f unique event name
 *  @param props - a key/value properties to add to the event
 *
 *  @return Yes if the name and props is not nil or empty
 */

-(BOOL)trackEvent:(NSString*)name prop:(NSDictionary*)props;

/*!
 *  sends a page view event to the database.
 *
 *  @param uniqueID - unique identifier of the page
 *  @param name - display name of the page
 *  @param section - the section that hold the page - can be nil
 *  @param DYContext - optional page context
 
 *  @return Yes if the uniqueID and name is not nil or empty
 */

-(BOOL)pageView:(NSString*)uniqueID name:(NSString*)name section:(NSString*)section context:(DYPageContext*)DYContext;

/*!
 *  Sets the site vars that will be sent at each event
 *  The vars will be sticky until clear method will send
 *
 *  @param vars - key/value set of site vars
 *
 *  @return Yes if vars is not nil or empty
 */

-(BOOL)setSiteVars:(NSDictionary*)vars;

/*!
 *  Clears the site vars that there keys are in the array
 *
 *  @param names - NSArray of NSStrings
 *
 *  @return Yes if names is not nil or empty
 */

-(BOOL)clearSiteVars:(NSArray*)names;


/*!
 *  sends a list of units impression
 *
 *  @param names - an array of units names
 *
 *  @return Yes if names is not nil or empty
 */

-(BOOL)trackUnitsImpression:(NSArray*)names;

/*!
 *  sends a list of units real impression
 *
 *  @param names - an array of units names
 *
 *  @return Yes if names is not nil or empty
 */


-(BOOL)trackUnitsRealImpression:(NSArray*)names;

/*!
 *  sends a unit clicked event
 *
 *  @param name - the name of the unit
 *
 *  @return Yes if names is not nil or empty
 */

-(BOOL)trackUnitClicked:(NSString*)name;

/*!
 *  sends a front page unit clicked event
 *
 *  @param frontpageID - the frontpage ID
 *  @param articleID - the unique identifier of the unit
 *  @param section - the section that contains the unit
 *  @param position - the position of the unit inside the section
 *
 *  @return Yes if the params are not nil or empty
 */

-(BOOL)trackFrontpage:(NSString*)frontpageID articleClicked:(NSString*)articleID inSection:(NSString*)section position:(int)position;

/*!
 *  returns the audiences that the user belongs to
 *
 *  @return Array of Audiences OR Null if no audience available
 */
-(NSArray*)getUserAudiences;

/////////////////////Experiments

/*!
 *  choose a variation for the given experiment id or name.
 *
 *  @param expID - experiment Name Or ID
 *
 *  @return an index from 0 to n-1 where n is the number of possible variations
 */

-(NSNumber*)chooseVariation:(id)expID;

/*!
 *  choose a variation for the given experiment id or name, regardless of previous results
 *
 *  @param expID - experiment Name Or ID
 *
 *  @return an index from 0 to n-1 where n is the number of possible variations
 */

-(NSNumber*)forceChooseVariation:(id)expID;


/*!
 *  choose a variation for the given experiment id or name,and return 
 *  the selected variation
 *
 *  @param expID - experiment Name Or ID
 *
 *  @return NSDictionary object with the properties
 */

-(NSDictionary*)chooseVariationAndGetData:(id)expID;

/*!
 *  choose a variation for the given experiment id or name,and return
 *  the selected variation
 *
 *  @param expID - experiment Name Or ID
 *
 *  @return NSDictionary object with the properties
 */


-(NSDictionary*)forceChooseVariationAndGetData:(id)expID;

/*!
 *  Choose a variation for a front page article
 *
 *  @param articleID - the article id as reffered in the admin
 *  @param frontpageID - the front page ID
 *  @param section - the section of the article
 *  @return the chosen variation or null if not exist
 */


-(NSDictionary*)getExperimentDataFor:(NSString*)articleID inFrontpage:(NSString*)frontpageID andSection:(NSString*)section;

/*!
 *  Get the chosen variations for all the front page experiments
 *
 *  @param frontpageID - front page ID
 *
 *  @return an array with all the chosen variations
 */

- (NSDictionary*)getAllExperimentsDataForFrontpage:(NSString*)frontpageID;



/*!
 *  get full chosen variation data for the given experiment
 *
 *  @param expID - experiment Name Or ID
 *
 *  @return NSDictionary object with the data
 */

-(NSDictionary*)getVariationData:(id)expID;

/*!
 *  get the variation properties for the given experiment
 *
 *  @param expID - experiment Name Or ID
 *
 *  @return NSDictionary object with the properties
 */

-(NSDictionary*)getVariationProperties:(id)expID;


/*!
 *  get the entire variation set defined on the server
 *
 *  @param expID - experiment Name Or ID
 *
 *  @return array of the variation original variation objects
 */

-(NSDictionary*)getServerVariations:(id)expID;


/*!
 *  Forces the choosing of a specific variation for the given experiment.
 *
 *  @param expID - experiment Name Or ID
 *  @param variationId - the variation id or name to use
 */

-(void)setVariation:(id)expID variationID:(NSString*)variationId;


/*!
 *  Convert the expName to ID
 *
 *  @param expName - experiment name
 *
 *  @return return the tech id matching the experiment name Or Null
 */

-(NSNumber*)expNameToId:(NSString*)expName;


/*!
 *  A utility method that returns the experiment variation ID for a
 *  given experiment name and variation name.
 *
 *  @param expID   - experiment id
 *  @param varName - variation name
 *
 *  @return the id of the experiment
 */

-(NSNumber*)varNameToId:(id)expID var:(NSString*)varName;


/*!
 *
 *  Returns the value assigned to a variable name specified
 *
 * @param varName - The name of the variable as maintained in the Dynamic Yield Admin Console
 * @param defaultValue - The value that should be assigned to the variable in case no value is returned
 *
 * @return the value of the smartVariable
 */

-(id)getSmartVariable:(NSString*)varName defaultValue:(id)defaultValue;

/*!
 *  Selects an HTML variation from the defined smart object and then assigns it
 * to the defined webview container; returns YES if the input parameters are valid. If
 * parameter fallBackURL is maintained, the HTML content will be assigned in case no
 * variation is returned from the Dynamic Yield server.
 * Use delegate <delegate name> to respond to no returned results manually.
 *
 *  @param webView    the webView to load
 *  @param smartObjID The smartObjectID
 *
 *  @return Yes if the params are not nil or empty
 */


-(BOOL)loadWebView:(UIWebView*)webView withSmartObject:(id)smartObjID fallbackURL:(NSURL*)fallBackURL;

/*!
 *  Selects an Image template variation from the defined smart object and then assigns it
 * to the defined imageview container; returns YES if the input parameters are valid. If
 * parameter fallBackURL is maintained, the URL content will be assigned in case no
 * variation is returned from the Dynamic Yield server.
 * Use delegate <delegate name> to respond to no returned results manually.
 *
 *  @param imageView    the imageView to load
 *  @param smartObjID The smartObjectID
 *
 *  @return Yes if the params are not nil or empty
 */

-(BOOL)loadImageView:(UIImageView*)imageView withSmartObject:(id)smartObjID fallbackURL:(NSURL*)fallBackURL;


/*!
 *  Get the recommended items for a given widget id in a specified context. The results are returned via the delegate.
 *
 *  @param widgetID - The recommendation widget ID as maintained in the Dynamic Yield admin console
 *  @param context - The current screen’s context
 *  @param itemsIDsOnly - Used to request only the recommended item’s identifiers (without additional item metadata).
 *  @param rcomDelegate - A delegate that receives the results and handles the recommended items presentation
 *
 *  @return Yes if the params are not nil or empty
 */

-(BOOL)sendRecommendationRequest:(NSString*)widgetID withContext:(DYPageContext*)context itemsIDsOnly:(BOOL)itemsIDsOnly andDelegate:(id<DYRecommendationsDelegate>)rcomDelegate;

/*!
 *  Sets the current user’s affinity attributes with key value pairs where the keys are product attributes and the value are the attribute value. 
 *
 *  @param affinities - Key value pairs where the keys are product attributes and the value are the attribute values
 *
 *  @return Yes if the params are not nil or empty
 */

-(BOOL)setRecommendationAffinities:(NSDictionary*)affinities;


/*!
 *  Reports a list of recommended items real impressions (i.e. were visible to user) within a given recommendation widget to the Dynamic Yield server.
 *
 *  @param widgetID - The recommendation widget ID used for receiving the recommendations items presented to the user
 *  @param itemIDs - An array of identifiers of recommendation items presented to the user
 *
 *  @return Yes if the params are not nil or empty
 */
-(BOOL)TrackRecomItemsRealImpression:(NSString*)widgetID andItemID:(NSArray*)itemIDs;

/*!
 *  Reports the identifier of a recommended item tapped by the user within a given recommendation widget to the Dynamic Yield server. Returns YES if the input parameters are valid.
 *
 *  @param widgetID - The recommendation widget ID used for receiving the recommendations items presented to the user
 *  @param itemID - The identifier of a recommendation items tapped by the user
 *
 *  @return Yes if the params are not nil or empty
 */

-(BOOL)TrackRecomItemClick:(NSString*)widgetID andItemID:(NSString*)itemID;


/*!
 *  Sets the Evaluator value
 *
 *  @param evaluatorID - the ID (not display name) of the evaluator
 *  @param params - the value of the evaluator
 *
 *  @return Yes if evaluatorID is not nil or empty
 */


-(BOOL)setEvaluator:(NSString*)evaluatorID forParams:(NSArray*)params;

/*!
 * Activates developer mode enabling advanced
 * logging and debugging of the content and flow
 *
 * @param enable - True/False to show logs
 */

-(void)enableDeveloperLogs:(BOOL)enable;

-(void)setAutoPageViewsTracking:(BOOL)toTrack;

@end
