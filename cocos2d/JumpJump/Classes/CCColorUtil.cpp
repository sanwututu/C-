//  
//  CCColorUtil.cpp  
//  quickcocos2dx  
//  
//  Created by Terran Tian on 13-11-19.  
//  Copyright (c) 2013Äê qeeplay.com. All rights reserved.  
//  
#include "CCColorUtil.h"  
#include "cocos2d.h"  
using namespace cocos2d;
void CCColorUtil::addGray(CCSprite* sp)
{
	do
	{
		CCGLProgram* pProgram = CCShaderCache::sharedShaderCache()->programForKey(kCCShader_PositionTextureGray);
		sp->setShaderProgram(pProgram);
		CHECK_GL_ERROR_DEBUG();

		sp->getShaderProgram()->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
		sp->getShaderProgram()->addAttribute(kCCAttributeNameColor, kCCVertexAttrib_Color);
		sp->getShaderProgram()->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
		CHECK_GL_ERROR_DEBUG();

		sp->getShaderProgram()->link();
		CHECK_GL_ERROR_DEBUG();

		sp->getShaderProgram()->updateUniforms();
		CHECK_GL_ERROR_DEBUG();
	} while (0);
}
void CCColorUtil::removeGray(CCSprite* sp)
{
	do
	{
		CCGLProgram* pProgram = CCShaderCache::sharedShaderCache()->programForKey(kCCShader_PositionTextureColor);
		sp->setShaderProgram(pProgram);
		CHECK_GL_ERROR_DEBUG();

		sp->getShaderProgram()->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
		sp->getShaderProgram()->addAttribute(kCCAttributeNameColor, kCCVertexAttrib_Color);
		sp->getShaderProgram()->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
		CHECK_GL_ERROR_DEBUG();

		sp->getShaderProgram()->link();
		CHECK_GL_ERROR_DEBUG();

		sp->getShaderProgram()->updateUniforms();
		CHECK_GL_ERROR_DEBUG();
	} while (0);
}
