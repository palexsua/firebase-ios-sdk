/*
 * Copyright 2020 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import <GoogleDataTransport/GDTCORStorageProtocol.h>

/** The flat file storage iterator. */
@interface GDTCORFlatFileStorageIterator : NSObject <GDTCORStorageEventIterator>

/** The queue on which the iterator will run. */
@property(nonatomic, readonly) dispatch_queue_t queue;

/** The target the iterator will work on. */
@property(nonatomic, readonly) GDTCORTarget target;

/** The list of event files to iterate over. This should be set before calling -nextEvent. */
@property(nonatomic) NSArray<NSString *> *eventFiles;

@end
