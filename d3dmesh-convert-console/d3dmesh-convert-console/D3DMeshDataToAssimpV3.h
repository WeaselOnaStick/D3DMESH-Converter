#pragma once
#ifndef D3DMESH_DATA_TO_ASSIMP_V3_H
#define D3DMESH_DATA_TO_ASSIMP_V3_H

//||||||||||||||||||||||||||||| INCLUDED DEPENDENCIES |||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||| INCLUDED DEPENDENCIES |||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||| INCLUDED DEPENDENCIES |||||||||||||||||||||||||||||

//THIRD PARTY: ASSIMP Library
#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/cimport.h>

//Standard C++ Library
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <filesystem>
#include <stdlib.h>

//Custom
#include "TelltaleD3DMeshFileV55.h"
#include "AssimpHelper.h"

//||||||||||||||||||||||||||||| D3DMESH DATA TO ASSIMP V3 |||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||| D3DMESH DATA TO ASSIMP V3 |||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||| D3DMESH DATA TO ASSIMP V3 |||||||||||||||||||||||||||||

static void BuildAssimpMeshFromD3DMeshV3(aiMesh* assimpMesh, TelltaleD3DMeshFileV55* d3dmeshFile, int d3dmeshIndexLOD, int d3dmeshIndexBatch, bool defaultMesh)
{
	T3MeshLOD d3dmeshLOD = d3dmeshFile->d3dmeshHeader.mLODs[d3dmeshIndexLOD];
	T3MeshBatch d3dmeshBatch;

	if (defaultMesh)
		d3dmeshBatch = d3dmeshLOD.mBatches0[d3dmeshIndexBatch];
	else
		d3dmeshBatch = d3dmeshLOD.mBatches1[d3dmeshIndexBatch];

	assimpMesh->mMaterialIndex = d3dmeshBatch.mMaterialIndex;

	//|||||||||||||||||||||||||||||||||||||||| VERTEX POSITIONS ||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||| VERTEX POSITIONS ||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||| VERTEX POSITIONS ||||||||||||||||||||||||||||||||||||||||
	//batch (doesn't work?)
	//int vertexCount = (d3dmeshBatch.mMaxVertIndex + 1) - d3dmeshBatch.mMinVertIndex;
	//int vertexStart = d3dmeshBatch.mMinVertIndex;
	
	//lod (doesn't work?)
	int vertexCount = d3dmeshLOD.mVertexCount;
	int vertexStart = d3dmeshLOD.mVertexStart;
	
	//total
	//int vertexCount = d3dmeshFile->d3dmeshHeader.mVertexCount;
	//int vertexStart = 0;

	assimpMesh->mNumVertices = vertexCount;

	assimpMesh->mVertices = new aiVector3D[vertexCount];

	if (d3dmeshFile->d3dmeshData.vertexNormals.size() > 0)
		assimpMesh->mNormals = new aiVector3D[vertexCount];

	if (d3dmeshFile->d3dmeshData.vertexTangents.size() > 0)
		assimpMesh->mTangents = new aiVector3D[vertexCount];

	for (int i = 0; i < vertexCount; i++)
		assimpMesh->mVertices[i] = GetAssimpVector3FromVector4(d3dmeshFile->d3dmeshData.vertexPositions[0][i + vertexStart]);

	if (d3dmeshFile->d3dmeshData.vertexNormals.size() > 0)
	{
		for (int i = 0; i < vertexCount; i++)
			assimpMesh->mNormals[i] = GetAssimpVector3FromVector4(d3dmeshFile->d3dmeshData.vertexNormals[0][i + vertexStart]);
	}

	if (d3dmeshFile->d3dmeshData.vertexTangents.size() > 0)
	{
		for (int i = 0; i < vertexCount; i++)
			assimpMesh->mTangents[i] = GetAssimpVector3FromVector4(d3dmeshFile->d3dmeshData.vertexTangents[0][i + vertexStart]);
	}

	for (int j = 0; j < d3dmeshFile->d3dmeshData.vertexColors.size(); j++)
	{
		assimpMesh->mColors[j] = new aiColor4D[vertexCount];

		for (int i = 0; i < vertexCount; i++)
			assimpMesh->mColors[j][i] = GetAssimpColor4FromVector4(d3dmeshFile->d3dmeshData.vertexColors[j][i + vertexStart]);
	}

	for (int j = 0; j < d3dmeshFile->d3dmeshData.vertexUVs.size(); j++)
	{
		assimpMesh->mNumUVComponents[j] = 2;
		assimpMesh->mTextureCoords[j] = new aiVector3D[vertexCount];

		for (int i = 0; i < vertexCount; i++)
			assimpMesh->mTextureCoords[j][i] = GetAssimpVector3FromVector4(d3dmeshFile->d3dmeshData.vertexUVs[j][i + vertexStart]);
	}

	//|||||||||||||||||||||||||||||||||||||||| VERTEX BLEND WEIGHTS ||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||| VERTEX BLEND WEIGHTS ||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||| VERTEX BLEND WEIGHTS ||||||||||||||||||||||||||||||||||||||||

	//|||||||||||||||||||||||||||||||||||||||| VERTEX BLEND INDEXES ||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||| VERTEX BLEND INDEXES ||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||| VERTEX BLEND INDEXES ||||||||||||||||||||||||||||||||||||||||

	//|||||||||||||||||||||||||||||||||||||||| MESH TRIANGLES ||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||| MESH TRIANGLES ||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||| MESH TRIANGLES ||||||||||||||||||||||||||||||||||||||||

	std::vector<aiFace> faces;

	for (int faceIndex = 0; faceIndex < d3dmeshBatch.mNumIndices; faceIndex += 3)
	{
		aiFace newFace = aiFace();

		newFace.mNumIndices = 3; //triangles are made up of 3 vertex positions, so indicies are 3
		newFace.mIndices = new unsigned int[newFace.mNumIndices];

		//assign each extracted triangle index to our assimp face
		newFace.mIndices[0] = d3dmeshFile->d3dmeshData.indexBuffers[0][faceIndex + 0 + d3dmeshBatch.mStartIndex] + d3dmeshBatch.mBaseIndex;
		newFace.mIndices[1] = d3dmeshFile->d3dmeshData.indexBuffers[0][faceIndex + 1 + d3dmeshBatch.mStartIndex] + d3dmeshBatch.mBaseIndex;
		newFace.mIndices[2] = d3dmeshFile->d3dmeshData.indexBuffers[0][faceIndex + 2 + d3dmeshBatch.mStartIndex] + d3dmeshBatch.mBaseIndex;

		//accumulate final assimp faces
		faces.push_back(newFace);
	}

	assimpMesh->mFaces = new aiFace[faces.size()];
	assimpMesh->mNumFaces = faces.size();

	std::copy(faces.begin(), faces.end(), assimpMesh->mFaces);
}

static void ExportD3DMeshToAssimpV3(TelltaleD3DMeshFileV55* d3dmeshFile, std::string fileName)
{
	//|||||||||||||||||||||||||||||||| D3DMESH PRE-SETUP ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| D3DMESH PRE-SETUP ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| D3DMESH PRE-SETUP ||||||||||||||||||||||||||||||||

	int meshMaterialCount = d3dmeshFile->d3dmeshHeader.mMaterials_ArrayLength;
	int lodCount = d3dmeshFile->d3dmeshHeader.mLODs.size();
	int defaultMeshCount = 0;
	int shadowMeshCount = 0;
	int totalSubmeshCount = 0;

	for (int i = 0; i < lodCount; i++)
	{
		defaultMeshCount += d3dmeshFile->d3dmeshHeader.mLODs[i].mBatches0_ArrayLength;
		shadowMeshCount += d3dmeshFile->d3dmeshHeader.mLODs[i].mBatches1_ArrayLength;
		totalSubmeshCount += d3dmeshFile->d3dmeshHeader.mLODs[i].mNumBatches;
	}

	//|||||||||||||||||||||||||||||||| ASSIMP INITALIZATION ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| ASSIMP INITALIZATION ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| ASSIMP INITALIZATION ||||||||||||||||||||||||||||||||
	//Create and setup the assimp scene

	//start by building a scene in assimp
	aiScene* assimpScene = new aiScene;

	//construct an empty scene with no flags
	assimpScene->mFlags = 0;
	assimpScene->mRootNode = NULL;

	//initalize the scene first with no meshes
	assimpScene->mNumMeshes = 0;
	assimpScene->mMeshes = NULL;

	//initalize the scene first with no materials
	assimpScene->mNumMaterials = 0;
	assimpScene->mMaterials = NULL;

	//initalize the scene first with no animations
	assimpScene->mNumAnimations = 0;
	assimpScene->mAnimations = NULL;

	//initalize the scene first with no textures
	assimpScene->mNumTextures = 0;
	assimpScene->mTextures = NULL;

	//initalize the scene first with no lights
	assimpScene->mNumLights = 0;
	assimpScene->mLights = NULL;

	//initalize the scene first with no cameras
	assimpScene->mNumCameras = 0;
	assimpScene->mCameras = NULL;
	assimpScene->mPrivate = NULL;

	//construct the root node to store the meshes
	aiNode* rootNode = new aiNode;
	assimpScene->mRootNode = rootNode;

	//|||||||||||||||||||||||||||||||| ASSIMP D3DMESH NODES SETUP ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| ASSIMP D3DMESH NODES SETUP ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| ASSIMP D3DMESH NODES SETUP ||||||||||||||||||||||||||||||||
	//Using assimp, we will create our node tree for the d3dmesh for organization

	assimpScene->mRootNode->mChildren = new aiNode * [1];
	assimpScene->mRootNode->mNumChildren = 1;

	aiNode* d3dmeshParentNode = new aiNode;
	d3dmeshParentNode->mName = aiString(d3dmeshFile->d3dmeshHeader.mName);
	d3dmeshParentNode->mChildren = new aiNode * [2];
	d3dmeshParentNode->mNumChildren = 2;

	aiNode* defaultMeshParentNode = new aiNode;
	defaultMeshParentNode->mName = aiString("Default");
	defaultMeshParentNode->mChildren = new aiNode * [lodCount];
	defaultMeshParentNode->mNumChildren = lodCount;

#if defined (ASSIMP_EXPORT_SHADOW)
	aiNode* shadowMeshParentNode = new aiNode;
	shadowMeshParentNode->mName = aiString("Shadow");
	shadowMeshParentNode->mChildren = new aiNode * [lodCount];
	shadowMeshParentNode->mNumChildren = lodCount;
#endif

	d3dmeshParentNode->mChildren[0] = defaultMeshParentNode;
	d3dmeshParentNode->mChildren[1] = shadowMeshParentNode;
	assimpScene->mRootNode->mChildren[0] = d3dmeshParentNode;

	for (int i = 0; i < lodCount; i++)
	{
		defaultMeshParentNode->mChildren[i] = new aiNode;
		defaultMeshParentNode->mChildren[i]->mName = "Default_LOD" + std::to_string(i);

#if defined (ASSIMP_EXPORT_SHADOW)
		shadowMeshParentNode->mChildren[i] = new aiNode;
		shadowMeshParentNode->mChildren[i]->mName = "Shadow_LOD" + std::to_string(i);
#endif
	}

	//|||||||||||||||||||||||||||||||| ASSIMP MATERIAL SETUP ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| ASSIMP MATERIAL SETUP ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| ASSIMP MATERIAL SETUP ||||||||||||||||||||||||||||||||
	//NOTE: With assimp, we have to create a set of materials for the main scene.
	//The meshes we will create later will point to one of these materials defined for the scene.

	//create empty materials
	assimpScene->mMaterials = new aiMaterial * [meshMaterialCount];

	for (int i = 0; i < meshMaterialCount; i++)
	{
		aiString assimpMaterialName = aiString(d3dmeshFile->d3dmeshHeader.mMaterials[i].mBaseMaterialName.ValueString());

		assimpScene->mMaterials[i] = new aiMaterial(); //create an actual material object
		assimpScene->mMaterials[i]->AddProperty(&assimpMaterialName, AI_MATKEY_NAME);
	}

	assimpScene->mNumMaterials = meshMaterialCount; //update the material count

	//|||||||||||||||||||||||||||||||| ASSIMP MESH SETUP ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| ASSIMP MESH SETUP ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| ASSIMP MESH SETUP ||||||||||||||||||||||||||||||||
	//NOTE: With assimp, we have to create a set of meshes for the main scene.
	//The nodes we created earlier will point to one of these meshes defined for the scene.

	assimpScene->mMeshes = new aiMesh * [totalSubmeshCount];

	for (int i = 0; i < totalSubmeshCount; i++)
		assimpScene->mMeshes[i] = new aiMesh;

	assimpScene->mNumMeshes = totalSubmeshCount;

	//|||||||||||||||||||||||||||||||| ASSIMP ASSIGNING D3DMESH NODES ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| ASSIMP ASSIGNING D3DMESH NODES ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| ASSIMP ASSIGNING D3DMESH NODES ||||||||||||||||||||||||||||||||
	//NOTE: With assimp, we have to create a set of meshes for the main scene.
	//The nodes we created earlier will point to one of these meshes defined for the scene.

	int assimpMeshIndex = 0;

	for (int i = 0; i < lodCount; i++)
	{
		int defaultMeshCurrentLODLevelSubmeshCount = d3dmeshFile->d3dmeshHeader.mLODs[i].mBatches0_ArrayLength;

#if defined (ASSIMP_EXPORT_SHADOW)
		int shadowMeshCurrentLODLevelSubmeshCount = d3dmeshFile->d3dmeshHeader.mLODs[i].mBatches1_ArrayLength;
#endif

		aiNode* defaultMeshParentLOD = defaultMeshParentNode->mChildren[i];

#if defined (ASSIMP_EXPORT_SHADOW)
		aiNode* shadowMeshParentLOD = shadowMeshParentNode->mChildren[i];
#endif

		defaultMeshParentLOD->mMeshes = new unsigned int[defaultMeshCurrentLODLevelSubmeshCount];

		for (int j = 0; j < defaultMeshCurrentLODLevelSubmeshCount; j++)
			defaultMeshParentLOD->mMeshes[j] = 0;

		defaultMeshParentLOD->mNumMeshes = defaultMeshCurrentLODLevelSubmeshCount;

#if defined (ASSIMP_EXPORT_SHADOW)
		shadowMeshParentLOD->mMeshes = new unsigned int[shadowMeshCurrentLODLevelSubmeshCount];

		for (int j = 0; j < shadowMeshCurrentLODLevelSubmeshCount; j++)
			shadowMeshParentLOD->mMeshes[j] = 0;

		shadowMeshParentLOD->mNumMeshes = shadowMeshCurrentLODLevelSubmeshCount;
#endif

		for (int j = 0; j < defaultMeshParentLOD->mNumMeshes; j++)
		{
			defaultMeshParentLOD->mMeshes[j] = assimpMeshIndex;
			assimpMeshIndex++;
		}

#if defined (ASSIMP_EXPORT_SHADOW)
		for (int j = 0; j < shadowMeshParentLOD->mNumMeshes; j++)
		{
			shadowMeshParentLOD->mMeshes[j] = assimpMeshIndex;
			assimpMeshIndex++;
		}
#endif
	}

	//|||||||||||||||||||||||||||||||| ASSIMP DEFAULT MESH CONVERSION ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| ASSIMP DEFAULT MESH CONVERSION ||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||| ASSIMP DEFAULT MESH CONVERSION ||||||||||||||||||||||||||||||||

	for (int i = 0; i < lodCount; i++)
	{
		for (int j = 0; j < defaultMeshParentNode->mChildren[i]->mNumMeshes; j++)
		{
			aiMesh* defaultSubmesh = assimpScene->mMeshes[defaultMeshParentNode->mChildren[i]->mMeshes[j]];
			defaultSubmesh->mName = "Default_LOD" + std::to_string(i) + "_Submesh" + std::to_string(j);

			BuildAssimpMeshFromD3DMeshV3(defaultSubmesh, d3dmeshFile, i, j, true);
		}

#if defined (ASSIMP_EXPORT_SHADOW)
		for (int j = 0; j < shadowMeshParentNode->mChildren[i]->mNumMeshes; j++)
		{
			aiMesh* shadowSubmesh = assimpScene->mMeshes[shadowMeshParentNode->mChildren[i]->mMeshes[j]];
			shadowSubmesh->mName = "Shadow_LOD" + std::to_string(i) + "_Submesh" + std::to_string(j);

			BuildAssimpMeshFromD3DMeshV3(shadowSubmesh, d3dmeshFile, i, j, false);
		}
#endif
	}

	//|||||||||||||||||||||||||||||||||||||||| ASSIMP EXPORT ||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||| ASSIMP EXPORT ||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||| ASSIMP EXPORT ||||||||||||||||||||||||||||||||||||||||

	//initalize our assimp exporter objects
	Assimp::Exporter assimpExporter;
	Assimp::ExportProperties* properties = new Assimp::ExportProperties;

	//currenty supported assimp export formats
	//[ASSIMP] ID : x Extension : x
	//[ASSIMP] ID : stp Extension : stp
	//[ASSIMP] ID : obj Extension : obj
	//[ASSIMP] ID : objnomtl Extension : obj
	//[ASSIMP] ID : stl Extension : stl
	//[ASSIMP] ID : stlb Extension : stl
	//[ASSIMP] ID : ply Extension : ply
	//[ASSIMP] ID : plyb Extension : ply
	//[ASSIMP] ID : 3ds Extension : 3ds
	//[ASSIMP] ID : gltf2 Extension : gltf
	//[ASSIMP] ID : glb2 Extension : glb
	//[ASSIMP] ID : gltf Extension : gltf
	//[ASSIMP] ID : glb Extension : glb
	//[ASSIMP] ID : assbin Extension : assbin
	//[ASSIMP] ID : assxml Extension : assxml
	//[ASSIMP] ID : x3d Extension : x3d
	//[ASSIMP] ID : fbx Extension : fbx
	//[ASSIMP] ID : fbxa Extension : fbx
	//[ASSIMP] ID : 3mf Extension : 3mf
	//[ASSIMP] ID : pbrt Extension : pbrt
	//[ASSIMP] ID : assjson Extension : json
	std::string id = "fbx";
	std::string extension = "fbx";

	//construct our final exported file path for the final mesh
	std::string exportPath = "OutputD3DMESH_TO_ASSIMP/" + fileName + "." + extension;

	std::cout << "[ASSIMP EXPORT] Exporting..." << std::endl;

	//redirect assimp logs to the console output so we can see if something goes wrong
	auto assimpExportStream = aiGetPredefinedLogStream(aiDefaultLogStream_STDOUT, NULL);
	aiAttachLogStream(&assimpExportStream);

	//export our final model using assimp
	aiReturn exportResult = assimpExporter.Export(assimpScene, id, exportPath, aiProcess_FindInvalidData | aiProcess_ValidateDataStructure, properties);

	//print to the console if we ran int oa problem
	if (exportResult == aiReturn_FAILURE || exportResult == aiReturn_OUTOFMEMORY)
		std::cout << "[ASSIMP EXPORT] Export Failed! Returned " << exportResult << std::endl;
	else
		std::cout << "[ASSIMP EXPORT] Export Success!" << std::endl;

	//detatch the log stream from assimp since we are done
	aiDetachLogStream(&assimpExportStream);
}

#endif