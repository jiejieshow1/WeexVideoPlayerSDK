//
//  BGWeexVideoPlayer.h
//  BGWeexVideoPlayer
//




#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

FOUNDATION_EXPORT NSString *const BLBPlayerStateChangedNotification;
FOUNDATION_EXPORT NSString *const BLBPlayerProgressChangedNotification;
FOUNDATION_EXPORT NSString *const BLBPlayerLoadProgressChangedNotification;

//播放器的几种状态
typedef NS_ENUM(NSInteger, TBPlayerState) {
    TBPlayerStateBuffering = 1,
    TBPlayerStatePlaying   = 2,
    TBPlayerStateStopped   = 3,
    TBPlayerStatePause     = 4
};

@interface BGWeexVideoPlayer : NSObject

@property (nonatomic, readonly) TBPlayerState state;
@property (nonatomic, readonly) CGFloat       loadedProgress;   //缓冲进度
@property (nonatomic, readonly) CGFloat       duration;         //视频总时间
@property (nonatomic, readonly) CGFloat       current;          //当前播放时间
@property (nonatomic, readonly) CGFloat       progress;         //播放进度 0~1
@property (nonatomic          ) BOOL          stopWhenAppDidEnterBackground;// default is YES


+ (instancetype)sharedInstance;
- (void)playWithUrl:(NSURL *)url showView:(UIView *)showView;
- (void)seekToTime:(CGFloat)seconds;

- (void)resume;
- (void)pause;
- (void)stop;

- (void)fullScreen;  //全屏
- (void)halfScreen;   //半屏
-(void)reloeaseObj;
@end
