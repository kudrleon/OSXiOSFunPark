//
//  ViewController.h
//  BackgroundPlayground
//
//  Created by Leonid Kudryavtsev on 3/11/16.
//  Copyright © 2016 Leonid Kudryavtsev. All rights reserved.
//

#import <UIKit/UIKit.h>
@import CoreBluetooth;
@import QuartzCore;

#define BLE_SERVICE_UUID_DEVICE_INFO @"180A"
#define BLE_SERVICE_UUID_HEART_RATE @"180D"

#define BLE_CHARACTERISTIC_UUID_HRM_MEASUREMENT @"2A37"
#define BLE_CHARACTERISTIC_UUID_HRM_BODY_LOCATION @"2A38"
#define BLE_CHARACTERISTIC_UUID_HRM_MANUFACTURER_NAME @"2A29"

@interface ViewController : UIViewController <CBCentralManagerDelegate, CBPeripheralDelegate>

@property (weak, nonatomic) IBOutlet UIButton *openCustom;

@property (nonatomic, strong) CBCentralManager *centralManager;
@property (nonatomic, strong) CBPeripheral     *HRMPeripheral;

// Properties for your Object controls
@property (nonatomic, strong) IBOutlet UILabel *heartRateBPM;
@property (nonatomic, strong) IBOutlet UITextView *deviceInfo;

// Properties to hold data characteristics for the peripheral device
@property (nonatomic, strong) NSString   *connected;
@property (nonatomic, strong) NSString   *bodyData;
@property (nonatomic, strong) NSString   *manufacturer;
@property (nonatomic, strong) NSString   *deviceData;
@property (assign) uint16_t heartRate;

// Instance method to get the heart rate BPM information
- (void) getHeartBPMData:(CBCharacteristic *)characteristic error:(NSError *)error;

// Instance methods to grab device Manufacturer Name, Body Location
- (void) getManufacturerName:(CBCharacteristic *)characteristic;
- (void) getBodyLocation:(CBCharacteristic *)characteristic;


@end

