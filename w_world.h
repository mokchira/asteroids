#ifndef W_WORLD_H
#define W_WORLD_H

#include "m_math.h"
#include "v_memory.h"

#define W_MAX_OBJ 1024 
#define W_MAX_EMIT 32
#define MAX_VERTS_PER_OBJ   16
#define MAX_INDICES_PER_OBJ 16
#define INIT_SPEED 0.005

typedef Vec2      Vertex;
typedef uint32_t  Index;

typedef struct {
    int      vertCount;
    int      vertIndex; // index to the first vertex
} Geo;

typedef struct {
    float radius;
} Collider;

typedef enum {
    BIG,
    SMALL,
    TINY,
    FINAL,
} AstStage;

typedef struct {
    Vec2      pos;
    Vec2      prevPos;
    float     angle;
    float     prevAngle;
    Vec2      vel;
    Vec2      accel;
    float     drag;
    float     angVel;
    float     angAccel;
    float     angDrag;
    float     mass;
    bool      destroyed;
    AstStage  stage;
} W_Object;

typedef struct {
    Vec2    pos;
    Vec2    vel;
    int     lifeTicks;
    Vec2    prevPos;
} W_Emitable;

extern int        w_ObjectCount;
extern int        w_EmitableCount;
extern W_Object   w_Objects[W_MAX_OBJ];
extern W_Emitable w_Emitables[W_MAX_EMIT];
extern Geo        w_Geos[W_MAX_OBJ];
extern V_block*   w_ObjectVertexBlock;
extern V_block*   w_EmitableVertexBlock;
extern Vertex*    w_ObjectVertexBuffer;
extern Vertex*    w_EmitableVertexBuffer;
extern Collider   w_Colliders[W_MAX_OBJ];

void w_Init(void);
void w_DetectCollisions(void);
void w_Update(void);
void w_CleanUp(void);
void w_UpdateDrawables(void);

#endif /* end of include guard: W_WORLD_H */
