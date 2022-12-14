//    Copyright (C) 2019 Parrot Drones SAS
//
//    Redistribution and use in source and binary forms, with or without
//    modification, are permitted provided that the following conditions
//    are met:
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in
//      the documentation and/or other materials provided with the
//      distribution.
//    * Neither the name of the Parrot Company nor the names
//      of its contributors may be used to endorse or promote products
//      derived from this software without specific prior written
//      permission.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
//    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
//    PARROT COMPANY BE LIABLE FOR ANY DIRECT, INDIRECT,
//    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
//    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
//    OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
//    AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
//    OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
//    SUCH DAMAGE.

#import <Foundation/Foundation.h>
#import "ArsdkCore.h"
#import "ArsdkRequest.h"

/** FlightLog status code */
typedef NS_ENUM(NSInteger, ArsdkFlightLogStatus) {
    // Numerical values must be kept in sync with C code (arsdk_flight_log_req_status)
    /** request succeeded */
    ArsdkFlightLogStatusOk = 0,
    /** request canceled by the user */
    ArsdkFlightLogStatusCanceled = 1,
    /** request failed */
    ArsdkFlightLogStatusFailed = 2,
    /** request aborted by disconnection, no more requests can be sent */
    ArsdkFlightLogStatusAborted = 3
};

/// Progress callback
typedef void(^ArsdkFlightLogDownloadProgress)(NSString * _Nonnull path, ArsdkFlightLogStatus status);

/// Completion callback
typedef void(^ArsdkFlightLogDownloadCompletion)(ArsdkFlightLogStatus status);


/**
 Arsdk Controller, FlightLog related functions
 */
@interface ArsdkCore (FlightLog)

/** FlightLog request */
- (nonnull ArsdkRequest *)downloadFlightLog:(int16_t)handle
                                 deviceType:(NSInteger)deviceType
                                       path:(nonnull NSString *)path
                                   progress:(nonnull ArsdkFlightLogDownloadProgress)progressBlock
                                 completion:(nonnull ArsdkFlightLogDownloadCompletion)completionBlock;
@end
