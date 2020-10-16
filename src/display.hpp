#ifndef DISPLAY_HPP
#define DISPLAY_HPP

enum Channel
{
  BEAT,
  CLOCK_DIV,
  CHANNEL_COUNT,
};

void display_num(Channel channel, int low, int high);
void setup_display();
void activate_channel(Channel channel);

#endif