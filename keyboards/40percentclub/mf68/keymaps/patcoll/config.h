#define TAPPING_TERM 200            // How long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold too
// #define TAPPING_TERM_PER_KEY        // Enables handling for per key TAPPING_TERM settings
// #define PERMISSIVE_HOLD             // Makes tap and hold keys trigger the hold if another key is pressed before releasing, even if it hasn't hit the TAPPING_TERM. See Permissive Hold for details

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64
