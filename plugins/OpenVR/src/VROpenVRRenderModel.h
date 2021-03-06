/*
 * Copyright Regents of the University of Minnesota, 2015.  This software is released under the following license: http://opensource.org/licenses/GPL-2.0
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 * code based on the hello_vr_opengl from openvr https://github.com/ValveSoftware/openvr
 * 
 * Code author(s): 
 * 		Ben Knorlein
 */



#ifndef VROPENVRRENDERMODEL_H_
#define VROPENVRRENDERMODEL_H_

#include <openvr.h>
#include <string>
#include "GL/glew.h"
#include <GL/gl.h>

namespace MinVR {
	class VROpenVRRenderModel {

public:
	VROpenVRRenderModel(const std::string & sRenderModelName);
	~VROpenVRRenderModel();

	bool BInit(const vr::RenderModel_t & vrModel, const vr::RenderModel_TextureMap_t & vrDiffuseTexture);
	void Cleanup();
	void Draw();
	const std::string & GetName() const { return m_sModelName; }

	private:
		GLuint m_glVertBuffer;
		GLuint m_glIndexBuffer;
		GLuint m_glVertArray;
		GLuint m_glTexture;
		GLsizei m_unVertexCount;
		std::string m_sModelName;
};


} /* namespace MinVR */

#endif /* VROPENVRRENDERMODEL_H_ */
