#ifndef HDMI_CEC_H
#define HDMI_CEC_H

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#include "task.h"
#define CEC_TASK_NAME "cec"
#define CECPIN 11

typedef struct {
  uint8_t *data;
  uint8_t len;
} hdmi_message_t;

typedef enum {
  HDMI_FRAME_STATE_START_LOW = 0,
  HDMI_FRAME_STATE_START_HIGH = 1,
  HDMI_FRAME_STATE_DATA_LOW = 2,
  HDMI_FRAME_STATE_DATA_HIGH = 3,
  HDMI_FRAME_STATE_EOM_LOW = 4,
  HDMI_FRAME_STATE_EOM_HIGH = 5,
  HDMI_FRAME_STATE_ACK_LOW = 6,
  HDMI_FRAME_STATE_ACK_HIGH = 7,
  HDMI_FRAME_STATE_ACK_END = 8,
  HDMI_FRAME_STATE_END = 9,
  HDMI_FRAME_STATE_ABORT = 10
} hdmi_frame_state_t;

typedef struct {
  uint64_t start;
  bool eom;
  hdmi_frame_state_t state;
} hdmi_ack_t;

typedef struct {
  hdmi_message_t *message;
  unsigned int bit;
  unsigned int byte;
  uint64_t start;
  bool first;
  bool eom;
  uint8_t address;
  hdmi_frame_state_t state;
} hdmi_frame_t;

extern TaskHandle_t xCECTask;

void cec_task(void *data);

#endif
