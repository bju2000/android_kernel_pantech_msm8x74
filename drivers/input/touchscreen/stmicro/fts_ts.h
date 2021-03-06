#ifndef _LINUX_FTS_TS_H_
#define _LINUX_FTS_TS_H_

#include <linux/device.h>
#include <linux/hrtimer.h>
#include <linux/fs.h>
#include <linux/delay.h>
#include <asm/uaccess.h>
#include <linux/gpio_switch.h>




#ifdef CONFIG_INPUT_BOOSTER
#include <linux/input/input_booster.h>
#endif

#include "fts.h"
#define dbg_cr(fmt, args...)      printk("[+++ TOUCH] " fmt, ##args)
#define dbg_i2c(fmt,args...)      if(pan_debug_state & PAN_TOUCH_DEBUG_I2C_MASK) printk("[+++ TOUCH] " fmt,##args)
#define dbg_op_err(fmt,args...)   if(pan_debug_state & PAN_TOUCH_DEBUG_OPERATION_ERR_MASK) printk("[+++ TOUCH] " fmt,##args)
#define dbg_op(fmt,args...)       if(pan_debug_state & PAN_TOUCH_DEBUG_OPERATION_MASK) printk("[+++ TOUCH] " fmt,##args)
#define dbg_ioctl(fmt,args...)    if(pan_debug_state & PAN_TOUCH_DEBUG_IOCTL_MASK) printk("[+++ TOUCH] " fmt,##args) 
#define dbg_firmw(fmt,args...)    if(pan_debug_state & PAN_TOUCH_DEBUG_FIRMWARE_MASK) printk("[+++ TOUCH] " fmt,##args)
#define dbg_func_in()			  if(pan_debug_state & PAN_TOUCH_DEBUG_FUNCTION_NAME_MASK) printk("[+++ TOUCH] %s Func In\n", __func__)
#define dbg_func_out()			  if(pan_debug_state & PAN_TOUCH_DEBUG_FUNCTION_NAME_MASK) printk("[+++ TOUCH] %s Func Out\n", __func__)
#define dbg_hw(fmt,args...)       if(pan_debug_state & PAN_TOUCH_DEBUG_HW_MASK) printk("[+++ TOUCH] " fmt,##args)
#define dbg_config(fmt,args...)   if(pan_debug_state & PAN_TOUCH_DEBUG_CONFIG_MASK) printk("[+++ TOUCH] " fmt,##args)
#define dbg_touch(fmt,args...)    if(pan_debug_state & (PAN_TOUCH_DEBUG_TOUCH_MASK|PAN_TOUCH_DEBUG_OPERATION_MASK)) printk("[+++ TOUCH] " fmt,##args)


//++ p11309 - 2013.12.22 for disabled by wcjeong
#define PAN_IRQ_WORKQUEUE
#define PAN_TSP_POWER_CTRL
#define SKY_PROCESS_CMD_KEY

//++ p13106 2014.1.16 for touchMonitor App
#define TOUCH_MONITOR
#define PAN_TOUCH_SET_PEN_MODE

//++ P13106 2014.2.19 Touch Event Block when flip cover closed.
#define PAN_TOUCH_EVENT_WITH_HALL_IC


#if !defined(CONFIG_INPUT_BOOSTER)
//#define TSP_BOOSTER
#endif

#ifdef TSP_BOOSTER
#include <linux/pm_qos.h>
#define TOUCH_BOOSTER_OFF_TIME	500
#define TOUCH_BOOSTER_CHG_TIME	130

#define TOUCH_BOOSTER_CPU_FRQ_1		1300000	/* CPU KFC 1.3GHz */
#define TOUCH_BOOSTER_MIF_FRQ_1		413000	/* MIF 413MHz */
#define TOUCH_BOOSTER_INT_FRQ_1		266000	/* INT 266MHz */
#define TOUCH_BOOSTER_CPU_FRQ_2		1300000	/* CPU KFC 1.3GHz */
#define TOUCH_BOOSTER_MIF_FRQ_2		206000	/* MIF 206MHz */
#define TOUCH_BOOSTER_INT_FRQ_2		160000	/* INT 160MHz */
#define TOUCH_BOOSTER_CPU_FRQ_3		1300000	/* CPU KFC 1.3GHz */
#define TOUCH_BOOSTER_MIF_FRQ_3		206000	/* MIF 206MHz */
#define TOUCH_BOOSTER_INT_FRQ_3		160000	/* INT 160MHz */
#endif


#define FIRMWARE_IC					"fts_ic"

#define FTS_MAX_FW_PATH	64
#define FTS_TS_DRV_VERSION			"Pan01"

#define STM_DEVICE_NAME				"STM"

#define FTS_ID0						0x39
#define FTS_ID1						0x80

#define FTS_FIFO_MAX				32
#define FTS_EVENT_SIZE				8

#define PRESSURE_MIN				0
#define PRESSURE_MAX				127
#define P70_PATCH_ADDR_START		0x00420000
#define FINGER_MAX					10
#define AREA_MIN					PRESSURE_MIN
#define AREA_MAX					PRESSURE_MAX

#define EVENTID_NO_EVENT					0x00
#define EVENTID_ENTER_POINTER				0x03
#define EVENTID_LEAVE_POINTER				0x04
#define EVENTID_MOTION_POINTER				0x05
#define EVENTID_HOVER_ENTER_POINTER			0x07
#define EVENTID_HOVER_LEAVE_POINTER			0x08
#define EVENTID_HOVER_MOTION_POINTER		0x09
#define EVENTID_PROXIMITY_IN				0x0B
#define EVENTID_PROXIMITY_OUT				0x0C

#define EVENTID_ERROR						0x0F
#define EVENT_ERROR_ITO         0x05
#define EVENTID_CONTROLLER_READY			0x10
#define EVENTID_SLEEPOUT_CONTROLLER_READY	0x11
#define EVENTID_RESULT_READ_REGISTER        0x12
#define EVENTID_STATUS_EVENT            	0x16
#define EVENTID_INTERNAL_RELEASE_INFO       0x19
#define EVENTID_EXTERNAL_RELEASE_INFO       0x1A

#define EVENTID_GESTURE                     0x20

#define INT_ENABLE							0x41
#define INT_DISABLE							0x00

#define READ_STATUS							0x84
#define READ_ONE_EVENT						0x85
#define READ_ALL_EVENT						0x86

#define SLEEPIN								0x90
#define SLEEPOUT							0x91
#define SENSEOFF							0x92
#define SENSEON								0x93

#define FTS_CMD_HOVER_OFF					0x94
#define FTS_CMD_HOVER_ON					0x95

#define FTS_CMD_SET_FAST_GLOVE_MODE			0x9D

#define FTS_CMD_MSHOVER_OFF					0x9E
#define FTS_CMD_MSHOVER_ON					0x9F
#define FTS_CMD_SET_NOR_GLOVE_MODE			0x9F

#define FLUSHBUFFER							0xA1
#define FORCECALIBRATION					0xA2
#define CX_TUNNING							0xA3
#define SELF_AUTO_TUNE						0xA4
#define FTS_CMD_PANEL_ITO_TEST        0xA7
#define FTS_CMD_CHARGER_PLUGGED				0xA8
#define FTS_CMD_CHARGER_UNPLUGGED			0xAB

#define FTS_CMD_RELEASEINFO					0xAA
#define FTS_CMD_STYLUS_OFF					0xAB
#define FTS_CMD_STYLUS_ON					0xAC

#ifdef PAN_KNOCK_ON
#define FTS_CMD_KNOCK_ON					0xAD
#endif

#define FTS_CMD_WRITE_PRAM          0xF0
#define FTS_CMD_BURN_PROG_FLASH     0xF2
#define FTS_CMD_ERASE_PROG_FLASH    0xF3
#define FTS_CMD_READ_FLASH_STAT     0xF4
#define FTS_CMD_UNLOCK_FLASH        0xF7
#define FTS_CMD_SAVE_FWCONFIG       0xFB
#define FTS_CMD_SAVE_CX_TUNING      0xFC

#define TSP_BUF_SIZE 1024
#define CMD_STR_LEN 32
#define CMD_RESULT_STR_LEN 512
#define CMD_PARAM_NUM 8

#define PAN_DATA_INIT -1
#define RAW_MAX	3750

#define FTS_TX_LENGTH		17
#define FTS_RX_LENGTH		29
#define READ_CHUNK_SIZE	2 //			(2 * 1024) - 16
#define FTS_MIN_RAWDATA 2250
#define FTS_MAX_RAWDATA 3750
#define FTS_PANTECH_PRODUCT_LINE
#define PAN_TOUCH_MODE_FINGER 0
#define PAN_TOUCH_MODE_GLOVE  1
#define PAN_TOUCH_MODE_PEN    2
#define PAN_TOUCH_MODE_MAX    3

#define PAN_SMART_COVER_STATE_OPENED  10
#define PAN_SMART_COVER_STATE_CLOSED  11

#define PAN_SMART_COVER_GPIO  65
#define PAN_SMART_COVER_CHECK_TIMER 500

struct tsp_control_pin {
	int	type;
	const char *name;

	struct {
		int	num;		
		int	direction;
	} gpio;

	struct {		
		int	volt;
		struct regulator *reg;
	} regulator;
};

struct pan_touch_state{
  u8 touch;
  u8 smart_cover;
  u8 smart_cover_from_ui;
  struct timer_list check_smart_cover;	
};  

/**
 * struct fts_finger - Represents fingers.
 * @ state: finger status (Event ID).
 * @ mcount: moving counter for debug.
 */
struct fts_finger {
	unsigned char state;
	unsigned short mcount;
};

struct fts_ts_info {
	struct device *dev;
	struct i2c_client *client;
	struct input_dev *input_dev;
	struct hrtimer timer;
	struct timer_list timer_charger;
	struct timer_list timer_firmware;
	struct work_struct work;
	int irq;
	int irq_type;
	bool irq_enabled;
	struct fts_i2c_platform_data *board;
	void (*register_cb) (void *);
	struct fts_callbacks callbacks;
	struct mutex lock;
	bool enabled;

#ifdef TSP_FACTORY_TEST
	struct device *fac_dev_ts;
	struct list_head cmd_list_head;
	u8 cmd_state;
	char cmd[CMD_STR_LEN];
	int cmd_param[CMD_PARAM_NUM];
	char cmd_result[CMD_RESULT_STR_LEN];
	int cmd_result_int;
	struct mutex cmd_lock;
	bool cmd_is_running;
	int SenseChannelLength;
	int ForceChannelLength;
	short *pFrame;
#endif

#ifdef TSP_BOOSTER
	bool dvfs_lock_status;
	struct delayed_work work_dvfs_off;
	struct delayed_work work_dvfs_chg;
	struct mutex dvfs_lock;
	struct pm_qos_request tsp_cpu_qos;
	struct pm_qos_request tsp_mif_qos;
	struct pm_qos_request tsp_int_qos;
	unsigned char boost_level;
#endif

	struct completion init_done;

	bool hover_enabled;
	bool mshover_enabled;
	bool flip_enable;

#if defined (FTS_SUPPORT_TA_MODE) || defined (FTS_SUPPORT_TA_MODE_PANTECH)
	bool TA_Pluged;
#endif

	int touch_count;
	struct fts_finger finger[FINGER_MAX];
	bool mflag_init_test;   /* for PANTECH ##1199 Touch Init Test */

#ifdef CONFIG_GLOVE_TOUCH
	int touch_mode;
#endif

	int ic_product_id;			/* product id of ic */
	int ic_revision_of_ic;		/* revision of reading from IC */
	int fw_version_of_ic;		/* firmware version of IC */
	int ic_revision_of_bin;		/* revision of reading from binary */
	int fw_version_of_bin;		/* firmware version of binary */
	int config_version_of_ic;		/* Config release data from IC */
	int config_version_of_bin;	/* Config release data from IC */
	unsigned short fw_main_version_of_ic;	/* firmware main version of IC */
	unsigned short fw_main_version_of_bin;	/* firmware main version of binary */
	int panel_revision;			/* Octa panel revision */

#ifdef FTS_SUPPORT_NOISE_PARAM
	struct fts_noise_param noise_param;
#endif

	struct mutex device_mutex;
	bool touch_stopped;
	int ito_test[2];

	struct pan_touch_state touch_mode_state;
	struct work_struct init_test_work;

	int (*stop_device) (struct fts_ts_info * info);
	int (*start_device) (struct fts_ts_info * info);

	int (*suspend) (struct fts_ts_info * info);
	int (*resume) (struct fts_ts_info * info);

	int (*fts_write_reg)(struct fts_ts_info *info, unsigned char *reg, unsigned short num_com);
	int (*fts_read_reg)(struct fts_ts_info *info, unsigned char *reg, int cnum, unsigned char *buf, int num);
	void (*fts_systemreset)(struct fts_ts_info *info);
	int (*fts_wait_for_ready)(struct fts_ts_info *info);
	void (*fts_command)(struct fts_ts_info *info, unsigned char cmd);
	int (*fts_get_version_info)(struct fts_ts_info *info);
#ifdef  PAN_TOUCH_SET_PEN_MODE
  void (*fts_pen_mode_set)(struct fts_ts_info *info, unsigned char onoff);
#endif	
};

#ifdef TSP_BOOSTER
enum BOOST_LEVEL {
	TSP_BOOSTER_DISABLE = 0,
	TSP_BOOSTER_LEVEL1,
	TSP_BOOSTER_LEVEL2,
	TSP_BOOSTER_LEVEL3,
	TSP_BOOSTER_LEVEL_MAX,
};

enum BOOST_MODE {
	TSP_BOOSTER_OFF = 0,
	TSP_BOOSTER_ON,
	TSP_BOOSTER_FORCE_OFF,
};
#endif

int fts_fw_update_on_probe(struct fts_ts_info *info);
int fts_fw_update_on_hidden_menu(struct fts_ts_info *info, int update_type);
void fts_fw_init(struct fts_ts_info *info);
int GetSystemStatus(struct fts_ts_info *info, unsigned char *val1, unsigned char *val2);

#ifdef PAN_TSP_IO
int pan_fts_io_register(struct fts_ts_info * info);
int pan_fts_io_unregister(void);
int ts_fops_open(struct inode *inode, struct file *filp);
long ts_fops_ioctl(struct file *filp, unsigned int cmd, unsigned long arg);
int open(struct inode *inode, struct file *file);
int release(struct inode *inode, struct file *file);
ssize_t write(struct file *file, const char *buf, size_t count, loff_t *ppos);
ssize_t read(struct file *file, char *buf, size_t count, loff_t *ppos);
long ioctl(struct file *file, unsigned int cmd, unsigned long arg);
#endif
void pan_hallic_ui_sync_timer_func(unsigned long data);

#ifdef TOUCH_MONITOR
#include <linux/proc_fs.h>
#include <linux/slab.h>


typedef struct {
	int         size;   /* maximum number of elements           */
	int         start;  /* index of oldest element              */
	int         end;    /* index at which to write new element  */
	char *elems;  /* vector of elements                   */
} CircularBuffer;

void cbInit(CircularBuffer *cb, int size);
void cbFree(CircularBuffer *cb);
int cbIsFull(CircularBuffer *cb);
int cbIsEmpty(CircularBuffer *cb);
void cbWrite(CircularBuffer *cb, char *elem);
void cbRead(CircularBuffer *cb, char *elem);
int read_log(char *page, char **start, off_t off, int count, int *eof, void *data_unused);
int read_touch_info(char *page, char **start, off_t off, int count, int *eof, void *data_unused);
void printp(const char *fmt, ...);
void init_proc(void);
void remove_proc(void);
#endif


#endif	//_LINUX_FTS_TS_H_
