#include "StGLTriggerBox.h"

#include <StGL/StGLProgram.h>
#include <StGL/StGLContext.h>
#include <StGLCore/StGLCore20.h>

#include <stAssert.h>

class ST_LOCAL StGLTriggerBox::StTriggerBoxProgram : public StGLProgram {

        private:

    StGLVarLocation atrVVertexLoc;
    StGLVarLocation uniFrameLoc;

        public:

    StTriggerBoxProgram()
    : StGLProgram("StTriggerBox"),
      atrVVertexLoc(),
      uniFrameLoc() {
        //
    }

    virtual ~StTriggerBoxProgram() {
        //
    }

    StGLVarLocation getVVertexLoc() const {
        return atrVVertexLoc;
    }

    virtual bool init(StGLContext& theCtx) {
        const char VERTEX_SHADER[] =
           "attribute vec4 vVertex; \
            void main(void) { \
                gl_Position = vVertex; \
            }";

# if 1
#if 0
	//LUK: OLED lapstop screen
        const char FRAGMENT_SHADER[] =
           "uniform vec4 uColor; \
            uniform int uFrame; \
            void main(void) { \
                int yFromBottom = int(floor(gl_FragCoord.y - 0.5)); \
                int xFromLeft = int(floor(gl_FragCoord.x - 0.5)); \
                if(uFrame == 2 && yFromBottom > 1156 && xFromLeft > 30 && xFromLeft < 74) { \
                    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\
                } else if(uFrame == 1 && yFromBottom > 1156 && xFromLeft > 110 && xFromLeft < 154) { \
                    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\
                } else if(yFromBottom > 1120 && xFromLeft < 188) { \
                    gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);\
                } else { \
                    gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0); \
                } \
            }";
#else
	//LUK: AOC screen
        const char FRAGMENT_SHADER[] =
           "uniform vec4 uColor; \
            uniform int uFrame; \
            void main(void) { \
                int yFromBottom = int(floor(gl_FragCoord.y - 0.5)); \
                int xFromLeft = int(floor(gl_FragCoord.x - 0.5)); \
                if(uFrame == 2 && yFromBottom > 1156-120 && xFromLeft > 5 && xFromLeft < 40) { \
                    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\
                } else if(uFrame == 1 && yFromBottom > 1156-120 && xFromLeft > 65 && xFromLeft < 100) { \
                    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\
                } else if(yFromBottom > 1140-120 && xFromLeft < 120) { \
                    gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);\
                } else { \
                    gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0); \
                } \
            }";
#endif	

#else
        const char FRAGMENT_SHADER[] =
           "uniform vec4 uColor; \
            uniform int uFrame; \
            void main(void) { \
                int yFromBottom = int(floor(gl_FragCoord.y - 0.5)); \
                int xFromLeft = int(floor(gl_FragCoord.x - 0.5)); \
                if(uFrame == 1 && yFromBottom > 1200-57 && xFromLeft > 35 && xFromLeft < 35+57) { \
                    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\
                } else if(uFrame == 2 && yFromBottom > 1200-57 && xFromLeft > 125 && xFromLeft < 125+57) { \
                    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\
                } else if(yFromBottom > 1200-83 && xFromLeft < 183+35) { \
                    gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);\
                } else { \
                    gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0); \
                } \
            }";
#endif


        StGLVertexShader aVertexShader(StGLProgram::getTitle());
        StGLAutoRelease aTmp1(theCtx, aVertexShader);
        aVertexShader.init(theCtx, VERTEX_SHADER);

        StGLFragmentShader aFragmentShader(StGLProgram::getTitle());
        StGLAutoRelease aTmp2(theCtx, aFragmentShader);
        aFragmentShader.init(theCtx, FRAGMENT_SHADER);
        if(!StGLProgram::create(theCtx)
           .attachShader(theCtx, aVertexShader)
           .attachShader(theCtx, aFragmentShader)
           .link(theCtx)) {
            return false;
        }

        atrVVertexLoc   = StGLProgram::getAttribLocation(theCtx, "vVertex");
        uniFrameLoc = StGLProgram::getUniformLocation(theCtx, "uFrame");

        return atrVVertexLoc.isValid() && uniFrameLoc.isValid();
    }

    using StGLProgram::use;
    void use(StGLContext&    theCtx,
             const GLint     theFrame) {
        StGLProgram::use(theCtx);
        theCtx.core20fwd->glUniform1i(uniFrameLoc, theFrame);
    }

};

StGLTriggerBox::StGLTriggerBox()
: StGLDeviceControl(),
  myProgram(NULL) {
}

StGLTriggerBox::~StGLTriggerBox() {
    ST_ASSERT(!myVertexBuf.isValid()
            && myProgram == NULL,
              "~StGLTriggerBox() with unreleased GL resources");
}

bool StGLTriggerBox::stglInit(StGLContext& theCtx) {
    const GLfloat QUAD_VERTICES[4 * 4] = {
         1.0f,  1.0f, 0.0f, 1.0f, // top-right
         1.0f, -1.0f, 0.0f, 1.0f, // bottom-right
        -1.0f,  1.0f, 0.0f, 1.0f, // top-left
        -1.0f, -1.0f, 0.0f, 1.0f  // bottom-left
    };
    myVertexBuf.init(theCtx, 4, 4, QUAD_VERTICES);

    myProgram = new StTriggerBoxProgram();
    return myProgram->init(theCtx);
}

void StGLTriggerBox::release(StGLContext& theCtx) {
    myVertexBuf.release(theCtx);
    if(myProgram != NULL) {
        myProgram->release(theCtx);
    }
    delete myProgram;
    myProgram = NULL;
}

void StGLTriggerBox::stglDraw(StGLContext& theCtx,
                               unsigned int theView,
                               const int    theWinWidth,
                               const int ) {
    if(!isActive() || myProgram == NULL || !myProgram->isValid()) {
        return;
    }

    theCtx.core20fwd->glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    theCtx.core20fwd->glEnable(GL_BLEND);
    myProgram->use(theCtx, theView);
        myVertexBuf.bindVertexAttrib(theCtx, myProgram->getVVertexLoc());
        theCtx.core20fwd->glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        myVertexBuf.unBindVertexAttrib(theCtx, myProgram->getVVertexLoc());
    myProgram->unuse(theCtx);
    theCtx.core20fwd->glDisable(GL_BLEND);

}
