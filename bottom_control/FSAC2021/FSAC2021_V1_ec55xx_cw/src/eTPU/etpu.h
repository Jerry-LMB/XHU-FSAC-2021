#include "mpc5554_vars.h"
#include "etpu_util.h"
#include "etpu_set.h"
#include "etpu_ic.h"
#include "etpu_pwm.h"

struct etpu_config_t my_etpu_config = {
  FS_ETPU_MISC_DISABLE, /* MCR register */
  FS_ETPU_MISC, /* MISC value from eTPU compiler link file */
  /* Configure eTPU engine A */
  FS_ETPU_FILTER_CLOCK_DIV8 +
  FS_ETPU_CHAN_FILTER_3SAMPLE +
  FS_ETPU_ENTRY_TABLE,
  /* Configure eTPU engine A timebases */
  FS_ETPU_TCR2CTL_DIV8 +
  ( 9 << 16) + /* TCR2 prescaler of 10 (9+1) */
  FS_ETPU_TCR1CTL_DIV2 +
  39, /* TCR1 prescaler of 40 (39+1) applied to sysclk/2 */
  0,
  /* Configure eTPU engine B */
  FS_ETPU_FILTER_CLOCK_DIV8 +
  FS_ETPU_CHAN_FILTER_3SAMPLE +
  FS_ETPU_ENTRY_TABLE,
  /* Configure eTPU engine B timebases */
  FS_ETPU_TCR2CTL_DIV8 +
  ( 9 << 16) + /* TCR2 prescaler of 10 (9+1) */
  FS_ETPU_TCR1CTL_DIV2 +
  39, /* TCR1 prescaler of 40 (39+1) applied to sysclk/2 */
  0
  };