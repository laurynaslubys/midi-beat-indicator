#ifndef DISPLAY_HPP
#define DISPLAY_HPP

enum Channel
{
  BEAT,
  CLOCK_DIV,
  CHANNEL_COUNT,
};

void display_num(Channel channel, int low, int high);
void display_bits(Channel channel, bool low_1, bool low_2, bool low_3, bool high_1, bool high_2, bool high_3);
void setup_display();
void activate_channel(Channel channel);
void start_blink(Channel channel, int on_millis, int off_millis);
void stop_blink(Channel channel);

#endif