#ifndef ENGINE_API_H
#define ENGINE_API_H

// Только то, что нужно знать пользователю
void init_system();
void run_sync_cycle();
void update_state(int id, int value);

#endif
