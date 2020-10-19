// Arduino Moving Average Library
// https://github.com/JChristensen/movingAvg
// Copyright (C) 2018 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

#ifndef MOVINGAVG_H_INCLUDED
#define MOVINGAVG_H_INCLUDED

template <typename T, typename U>
class movingAvg
{
public:
  movingAvg(int interval)
      : m_interval(interval), m_nbrReadings(0), m_sum(0), m_next(0)
  {
  }
  void begin();
  T reading(T newReading);
  T getAvg();
  int getCount() { return m_nbrReadings; }
  void reset();
  T *getReadings() { return m_readings; }

private:
  int m_interval;    // number of data points for the moving average
  int m_nbrReadings; // number of readings
  U m_sum;           // sum of the m_readings array
  int m_next;        // index to the next reading
  T *m_readings;     // pointer to the dynamically allocated interval array
};

// initialize - allocate the interval array
template <typename T, typename U>
void movingAvg<T, U>::begin()
{
  m_readings = new T[m_interval];
}

// add a new reading and return the new moving average
template <typename T, typename U>
T movingAvg<T, U>::reading(T newReading)
{
  // add each new data point to the sum until the m_readings array is filled
  if (m_nbrReadings < m_interval)
  {
    ++m_nbrReadings;
    m_sum = m_sum + newReading;
  }
  // once the array is filled, subtract the oldest data point and add the new one
  else
  {
    m_sum = m_sum - m_readings[m_next] + newReading;
  }

  m_readings[m_next] = newReading;
  if (++m_next >= m_interval)
    m_next = 0;
  return (m_sum + m_nbrReadings / 2) / m_nbrReadings;
}

// just return the current moving average
template <typename T, typename U>
T movingAvg<T, U>::getAvg()
{
  return (m_sum + m_nbrReadings / 2) / m_nbrReadings;
}

// start the moving average over again
template <typename T, typename U>
void movingAvg<T, U>::reset()
{
  m_nbrReadings = 0;
  m_sum = 0;
  m_next = 0;
}

#endif
