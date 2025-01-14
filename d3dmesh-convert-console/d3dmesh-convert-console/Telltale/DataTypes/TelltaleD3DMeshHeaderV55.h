#pragma once
#ifndef TELLTALE_D3DMESH_HEADER_55_H
#define TELLTALE_D3DMESH_HEADER_55_H

//||||||||||||||||||||||||||||| INCLUDED DEPENDENCIES |||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||| INCLUDED DEPENDENCIES |||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||| INCLUDED DEPENDENCIES |||||||||||||||||||||||||||||

//Custom
#include "../../Binary/BinarySerialization.h"
#include "../../Binary/BinaryDeserialization.h"
#include "../../Helper/JsonHelper.h"
#include "../../Telltale/DataTypes/Symbol.h"
#include "../../Telltale/DataTypes/Vector3.h"
#include "../../Telltale/DataTypes/TelltaleInternalResource.h"
#include "../../Telltale/DataTypes/T3MeshLOD.h"
#include "../../Telltale/DataTypes/T3MeshBoneEntry.h"
#include "../../Telltale/DataTypes/T3MeshLocalTransformEntry.h"
#include "../../Telltale/DataTypes/T3MaterialRequirements.h"
#include "../../Telltale/DataTypes/T3GFXBuffer.h"
#include "../../Telltale/DataTypes/GFXPlatformAttributeParams.h"
#include "../../Telltale/DataTypes/T3MeshMaterial.h"
#include "../../Telltale/DataTypes/T3MeshEffectPreload.h"

//||||||||||||||||||||||||||||| TELLTALE D3DMESH HEADER V55 |||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||| TELLTALE D3DMESH HEADER V55 |||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||| TELLTALE D3DMESH HEADER V55 |||||||||||||||||||||||||||||

struct TelltaleD3DMeshHeaderV55
{
	unsigned int mNameBlockSize;
	std::string mName;
	unsigned int mVersion;
	char mToolProps;
	float mLightmapGlobalScale;
	unsigned int mLightmapTexCoordVersion;
	Symbol mLODParamCRC;
	unsigned int mInternalResourcesCount;
	std::vector<TelltaleInternalResource> mInternalResources;
	unsigned int mToolPropsBlockSize;
	std::vector<char> mToolPropsData;
	char mHasOcclusionData;
	unsigned int mOcclusionDataBlockSize;
	std::vector<char> mOcclusionData;
	unsigned int mT3MeshDataBlockSize;

	/// <summary>
	/// [4 bytes]
	/// <para> (CALCULATION) to calculate array capacity... </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the array capacity. </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the amount of elements in the array. </para>
	/// <para> Then add the result of [ (element byte size) x (amount of elements) ] </para>
	/// </summary>
	unsigned int mLODs_ArrayCapacity;
	unsigned int mLODs_ArrayLength;
	std::vector<T3MeshLOD> mLODs;

	/// <summary>
	/// [4 bytes]
	/// <para> (CALCULATION) to calculate array capacity... </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the array capacity. </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the amount of elements in the array. </para>
	/// <para> Then add the result of [ (element byte size) x (amount of elements) ] </para>
	/// </summary>
	unsigned int mTextures_ArrayCapacity;
	unsigned int mTextures_ArrayLength;
	std::vector<char> mTexturesData;

	/// <summary>
	/// [4 bytes]
	/// <para> (CALCULATION) to calculate array capacity... </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the array capacity. </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the amount of elements in the array. </para>
	/// <para> Then add the result of [ (element byte size) x (amount of elements) ] </para>
	/// </summary>
	unsigned int mMaterials_ArrayCapacity;
	unsigned int mMaterials_ArrayLength;
	std::vector<T3MeshMaterial> mMaterials;

	/// <summary>
	/// [4 bytes]
	/// <para> (CALCULATION) to calculate array capacity... </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the array capacity. </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the amount of elements in the array. </para>
	/// <para> Then add the result of [ (element byte size) x (amount of elements) ] </para>
	/// </summary>
	unsigned int mMaterialOverrides_ArrayCapacity;
	unsigned int mMaterialOverrides_ArrayLength;
	std::vector<char> mMaterialOverridesData;

	/// <summary>
	/// [4 bytes]
	/// <para> (CALCULATION) to calculate array capacity... </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the array capacity. </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the amount of elements in the array. </para>
	/// <para> Then add the result of [ (element byte size) x (amount of elements) ] </para>
	/// </summary>
	unsigned int mBones_ArrayCapacity;
	unsigned int mBones_ArrayLength;
	std::vector<T3MeshBoneEntry> mBones;

	/// <summary>
	/// [4 bytes]
	/// <para> (CALCULATION) to calculate array capacity... </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the array capacity. </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the amount of elements in the array. </para>
	/// <para> Then add the result of [ (element byte size) x (amount of elements) ] </para>
	/// </summary>
	unsigned int mLocalTransforms_ArrayCapacity;
	unsigned int mLocalTransforms_ArrayLength;
	std::vector<T3MeshLocalTransformEntry> mLocalTransforms;
	T3MaterialRequirements mMaterialRequirements;
	unsigned int mVertexStreams_BlockSize; //value seems to always be 8
	unsigned int mVertexStreams;
	BoundingBox mBoundingBox;
	BoundingSphere mBoundingSphere;
	unsigned int mEndianType;
	Vector3 mPositionScale;
	Vector3 mPositionWScale;
	Vector3 mPositionOffset;
	float mLightmapTexelAreaPerSurfaceArea;
	Symbol mPropertyKeyBase;
	unsigned int mVertexCount;
	unsigned int mFlags;

	/// <summary>
	/// [4 bytes]
	/// <para> (CALCULATION) to calculate array capacity... </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the array capacity. </para>
	/// <para> Add 4, as this is the size of a uint32 that represents the amount of elements in the array. </para>
	/// <para> Then add the result of [ (element byte size) x (amount of elements) ] </para>
	/// </summary>
	unsigned int mMeshPreload_ArrayCapacity;
	unsigned int mMeshPreload_ArrayLength;
	std::vector<T3MeshEffectPreload> mMeshPreload;

	unsigned int mUVLayersCount;
	unsigned int UNKNOWN2;
	unsigned int mVertexCountPerInstance;
	unsigned int mIndexBufferCount;
	unsigned int mVertexBufferCount;
	unsigned int mAttributeCount;
	std::vector<GFXPlatformAttributeParams> GFXPlatformAttributeParamsArray;
	std::vector<T3GFXBuffer> mIndexBuffers;
	std::vector<T3GFXBuffer> mVertexBuffers;

	//||||||||||||||||||||||||||||| CONSTRUCTORS |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| CONSTRUCTORS |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| CONSTRUCTORS |||||||||||||||||||||||||||||

	TelltaleD3DMeshHeaderV55()
	{
		mNameBlockSize = 0;
		mName = "";
		mVersion = 0;
		mToolProps = 0;
		mLightmapGlobalScale = 0.0f;
		mLightmapTexCoordVersion = 0;
		mLODParamCRC = {};
		mInternalResourcesCount = 0;
		mInternalResources = {};
		mToolPropsBlockSize = 0;
		mToolPropsData = {};
		mHasOcclusionData = 0;
		mOcclusionDataBlockSize = 0;
		mOcclusionData = {};
		mT3MeshDataBlockSize = 0;
		mLODs_ArrayCapacity = 0;
		mLODs_ArrayLength = 0;
		mLODs = {};
		mTextures_ArrayCapacity = 0;
		mTextures_ArrayLength = 0;
		mTexturesData = {};
		mMaterials_ArrayCapacity = 0;
		mMaterials_ArrayLength = 0;
		mMaterials = {};
		mMaterialOverrides_ArrayCapacity = 0;
		mMaterialOverrides_ArrayLength = 0;
		mMaterialOverridesData = {};
		mBones_ArrayCapacity = 0;
		mBones_ArrayLength = 0;
		mBones = {};
		mLocalTransforms_ArrayCapacity = 0;
		mLocalTransforms_ArrayLength = 0;
		mLocalTransforms = {};
		mMaterialRequirements = {};
		mVertexStreams_BlockSize = 0;
		mVertexStreams = 0;
		mBoundingBox = {};
		mBoundingSphere = {};
		mEndianType = 0;
		mPositionScale = {};
		mPositionWScale = {};
		mPositionOffset = {};
		mLightmapTexelAreaPerSurfaceArea = 0.0f;
		mPropertyKeyBase = {};
		mVertexCount = 0;
		mFlags = 0;
		mMeshPreload_ArrayCapacity = 0;
		mMeshPreload_ArrayLength = 0;
		mMeshPreload = {};
		mUVLayersCount = 0;
		UNKNOWN2 = 0;
		mVertexCountPerInstance = 0;
		mIndexBufferCount = 0;
		mVertexBufferCount = 0;
		mAttributeCount = 0;
		GFXPlatformAttributeParamsArray = {};
		mIndexBuffers = {};
		mVertexBuffers = {};
	};

	TelltaleD3DMeshHeaderV55(std::ifstream* inputFileStream)
	{
		mNameBlockSize = ReadUInt32FromBinary(inputFileStream);
		mName = ReadLengthPrefixedStringFromBinary(inputFileStream);
		mVersion = ReadUInt32FromBinary(inputFileStream);
		mToolProps = ReadInt8FromBinary(inputFileStream);
		mLightmapGlobalScale = ReadFloat32FromBinary(inputFileStream);
		mLightmapTexCoordVersion = ReadUInt32FromBinary(inputFileStream);
		mLODParamCRC = Symbol(inputFileStream);

		//parse the internal resources block, this was difficult to track down but this basically contains propertysets or references to resources uses (i.e. materials)
		mInternalResourcesCount = ReadUInt32FromBinary(inputFileStream);

		for (int i = 0; i < mInternalResourcesCount; i++)
			mInternalResources.push_back(TelltaleInternalResource(inputFileStream)); //IMPORTANT NOTE: this is mostly skipped (we still keep the block of bytes so we can write later)

		//parse the tool property set block, this shouldn't technically have any data since this is the final shipped file.
		mToolPropsBlockSize = ReadUInt32FromBinary(inputFileStream);
		mToolPropsData = ReadByteVectorBufferFromBinary(inputFileStream, mToolPropsBlockSize); //IMPORTANT NOTE: this is mostly skipped (we still keep the block of bytes so we can write later)

		//parse the occlusion data block, this contains occlusion culling information regarding the mesh.
		mHasOcclusionData = ReadInt8FromBinary(inputFileStream);

		//if this is true then we need to skip it (ASCII '1' is true, ASCII '0' is false)
		if (mHasOcclusionData == '1')
		{
			mOcclusionDataBlockSize = ReadUInt32FromBinary(inputFileStream);
			mOcclusionData = ReadByteVectorBufferFromBinary(inputFileStream, mOcclusionDataBlockSize - 4); //IMPORTANT NOTE: this is mostly skipped (we still keep the block of bytes so we can write later)
		}

		//this is the start of the main T3MeshData block
		mT3MeshDataBlockSize = ReadUInt32FromBinary(inputFileStream);

		//parse the LODs associated with the mesh (oddly enough telltale didn't use LODs very often?)
		mLODs_ArrayCapacity = ReadUInt32FromBinary(inputFileStream);
		mLODs_ArrayLength = ReadUInt32FromBinary(inputFileStream);

		for (int i = 0; i < mLODs_ArrayLength; i++)
			mLODs.push_back(T3MeshLOD(inputFileStream));

		//parse the textures block (NOTE: This does not contain actual texture data, just references to it)
		mTextures_ArrayCapacity = ReadUInt32FromBinary(inputFileStream);
		mTextures_ArrayLength = ReadUInt32FromBinary(inputFileStream);
		mTexturesData = ReadByteVectorBufferFromBinary(inputFileStream, mTextures_ArrayCapacity - 8); //IMPORTANT NOTE: this is mostly skipped (we still keep the block of bytes so we can write later)

		//parse the materials block
		mMaterials_ArrayCapacity = ReadUInt32FromBinary(inputFileStream);
		mMaterials_ArrayLength = ReadUInt32FromBinary(inputFileStream);

		for (int i = 0; i < mMaterials_ArrayLength; i++)
			mMaterials.push_back(T3MeshMaterial(inputFileStream));

		//parse the materials overrides block
		mMaterialOverrides_ArrayCapacity = ReadUInt32FromBinary(inputFileStream);
		mMaterialOverrides_ArrayLength = ReadUInt32FromBinary(inputFileStream);
		mMaterialOverridesData = ReadByteVectorBufferFromBinary(inputFileStream, mMaterialOverrides_ArrayCapacity - 8); //IMPORTANT NOTE: this is mostly skipped (we still keep the block of bytes so we can write later)

		//parse the rigging bones block
		mBones_ArrayCapacity = ReadUInt32FromBinary(inputFileStream);
		mBones_ArrayLength = ReadUInt32FromBinary(inputFileStream);

		for (int i = 0; i < mBones_ArrayLength; i++)
			mBones.push_back(T3MeshBoneEntry(inputFileStream));

		//parse the rigging bones block
		mLocalTransforms_ArrayCapacity = ReadUInt32FromBinary(inputFileStream);
		mLocalTransforms_ArrayLength = ReadUInt32FromBinary(inputFileStream);

		for (int i = 0; i < mLocalTransforms_ArrayLength; i++)
			mLocalTransforms.push_back(T3MeshLocalTransformEntry(inputFileStream));

		//parse other misc information in the d3dmesh header
		mMaterialRequirements = T3MaterialRequirements(inputFileStream);
		mVertexStreams_BlockSize = ReadUInt32FromBinary(inputFileStream); //value seems to always be 8
		mVertexStreams = ReadUInt32FromBinary(inputFileStream);
		mBoundingBox = BoundingBox(inputFileStream);
		mBoundingSphere = BoundingSphere(inputFileStream);
		mEndianType = ReadUInt32FromBinary(inputFileStream);
		mPositionScale = Vector3(inputFileStream);
		mPositionWScale = Vector3(inputFileStream);
		mPositionOffset = Vector3(inputFileStream);
		mLightmapTexelAreaPerSurfaceArea = ReadFloat32FromBinary(inputFileStream);
		mPropertyKeyBase = Symbol(inputFileStream);
		mVertexCount = ReadUInt32FromBinary(inputFileStream);
		mFlags = ReadUInt32FromBinary(inputFileStream);

		//parse the mesh preload block
		mMeshPreload_ArrayCapacity = ReadUInt32FromBinary(inputFileStream);
		mMeshPreload_ArrayLength = ReadUInt32FromBinary(inputFileStream);

		for (int i = 0; i < mMeshPreload_ArrayLength; i++)
			mMeshPreload.push_back(T3MeshEffectPreload(inputFileStream));

		std::cout << inputFileStream->tellg();
		mUVLayersCount = ReadUInt32FromBinary(inputFileStream);
		for (int i = 0; i < mUVLayersCount; i++)
		{
			inputFileStream->seekg((int)inputFileStream->tellg()+20);
		}

		UNKNOWN2 = ReadUInt32FromBinary(inputFileStream);
		mVertexCountPerInstance = ReadUInt32FromBinary(inputFileStream);
		mIndexBufferCount = ReadUInt32FromBinary(inputFileStream);
		mVertexBufferCount = ReadUInt32FromBinary(inputFileStream);
		mAttributeCount = ReadUInt32FromBinary(inputFileStream);

		//parse the table of GFXPlatformAttributes, this is important as this is used during the vertex buffer parsing later to identify what buffers contain what data.
		for (int i = 0; i < mAttributeCount; i++)
			GFXPlatformAttributeParamsArray.push_back(GFXPlatformAttributeParams(inputFileStream));

		//parse the table of GFXBuffer data, these are "index" buffers (i.e. triangle indicies)
		for (int i = 0; i < mIndexBufferCount; i++)
			mIndexBuffers.push_back(T3GFXBuffer(inputFileStream));

		//parse the table of GFXBuffer data, these are "vertex" buffers (i.e. vertex position, normal, uv, etc)
		for (int i = 0; i < mVertexBufferCount; i++)
			mVertexBuffers.push_back(T3GFXBuffer(inputFileStream));
	};

	//||||||||||||||||||||||||||||| UPDATE STRUCTURES |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| UPDATE STRUCTURES |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| UPDATE STRUCTURES |||||||||||||||||||||||||||||
	//NOTE: This is critical as any mishap in regards to new/removed data will crash the game.
	//So in advance we need to update all structural values (block sizes, array lengths, array capacities) to make sure everything lines up.

	void UpdateStructures()
	{
		//temp variables, used to recalculate the bounding box/sphere for the current T3MeshLOD
		glm::vec3 newBoundingBoxMinimum = glm::vec3(FLT_MAX);
		glm::vec3 newBoundingBoxMaximum = glm::vec3(FLT_MIN);

		//update the name block binary size if it was changed
		mNameBlockSize = 8 + mName.length();

		//set the count here to match the array length of the actual data
		mInternalResourcesCount = mInternalResources.size();

		for (int i = 0; i < mInternalResourcesCount; i++)
			mInternalResources[i].UpdateStructures();

		//set the count here to match the array length of the actual data
		mLODs_ArrayLength = mLODs.size();
		mLODs_ArrayCapacity = 8;

		//start from zero, and recalculate the total vertex count of the object
		mVertexCount = 0;

		for (int i = 0; i < mLODs_ArrayLength; i++) 
		{
			mLODs[i].UpdateStructure();
			mLODs_ArrayCapacity += mLODs[i].GetByteSize();
			mVertexCount += mLODs[i].mVertexCount;

			//calculate new min/max for the current LOD level using each T3MeshBatch bounding box
			newBoundingBoxMinimum = glm::min(newBoundingBoxMinimum, Get_vec3_FromVector3(mLODs[i].mBoundingBox.mMin));
			newBoundingBoxMaximum = glm::max(newBoundingBoxMaximum, Get_vec3_FromVector3(mLODs[i].mBoundingBox.mMax));
		}

		mMaterials_ArrayLength = mMaterials.size();
		mMaterials_ArrayCapacity = 8;

		for (int i = 0; i < mMaterials_ArrayLength; i++)
		{
			mMaterials[i].UpdateStructure();
			mMaterials_ArrayCapacity += mMaterials[i].GetByteSize();
		}

		mBones_ArrayLength = mBones.size();
		mBones_ArrayCapacity = 8;

		for (int i = 0; i < mBones_ArrayLength; i++)
		{
			mBones[i].UpdateStructures();
			mBones_ArrayCapacity += mBones[i].GetByteSize();
		}

		mLocalTransforms_ArrayLength = mLocalTransforms.size();
		mLocalTransforms_ArrayCapacity = 8;

		for (int i = 0; i < mLocalTransforms_ArrayLength; i++)
		{
			mLocalTransforms[i].UpdateStructures();
			mLocalTransforms_ArrayCapacity += mLocalTransforms[i].GetByteSize();
		}

		mMaterialRequirements.UpdateStructures();
		mBoundingSphere.UpdateStructures();

		mMeshPreload_ArrayLength = mMeshPreload.size();
		mMeshPreload_ArrayCapacity = 8;

		for (int i = 0; i < mMeshPreload_ArrayLength; i++)
		{
			mMeshPreload[i].UpdateStructures();
			mMeshPreload_ArrayCapacity += mMeshPreload[i].GetByteSize();
		}

		mAttributeCount = GFXPlatformAttributeParamsArray.size();
		mIndexBufferCount = mIndexBuffers.size();
		mVertexBufferCount = mVertexBuffers.size();

		for (int i = 0; i < mIndexBufferCount; i++)
			mIndexBuffers[i].UpdateIndexBuffer();

		for (int i = 0; i < mVertexBufferCount; i++)
			mVertexBuffers[i].UpdateVertexBuffer(&GFXPlatformAttributeParamsArray[i]);

		mT3MeshDataBlockSize = GetT3MeshDataByteSize();

		mBoundingBox.mMin = newBoundingBoxMinimum;
		mBoundingBox.mMax = newBoundingBoxMaximum;
		mBoundingSphere.SetBoundingSphereBasedOnBoundingBox(mBoundingBox);
	}

	//||||||||||||||||||||||||||||| BINARY SERIALIZE |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| BINARY SERIALIZE |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| BINARY SERIALIZE |||||||||||||||||||||||||||||

	void BinarySerialize(std::ofstream* outputFileStream)
	{
		WriteUInt32ToBinary(outputFileStream, mNameBlockSize);
		WriteLengthPrefixedStringToBinary(outputFileStream, mName);
		WriteUInt32ToBinary(outputFileStream, mVersion);
		WriteUInt8ToBinary(outputFileStream, mToolProps);
		WriteFloat32ToBinary(outputFileStream, mLightmapGlobalScale);
		WriteUInt32ToBinary(outputFileStream, mLightmapTexCoordVersion);
		mLODParamCRC.BinarySerialize(outputFileStream);
		WriteUInt32ToBinary(outputFileStream, mInternalResourcesCount);

		for (int i = 0; i < mInternalResourcesCount; i++)
			mInternalResources[i].BinarySerialize(outputFileStream);

		WriteUInt32ToBinary(outputFileStream, mToolPropsBlockSize);
		WriteByteVectorBufferToBinary(outputFileStream, mToolPropsData);
		WriteUInt8ToBinary(outputFileStream, mHasOcclusionData);

		//if this is true then we need to skip it (ASCII '1' is true, ASCII '0' is false)
		if (mHasOcclusionData == '1')
		{
			WriteUInt32ToBinary(outputFileStream, mOcclusionDataBlockSize);
			WriteByteVectorBufferToBinary(outputFileStream, mOcclusionData);
		}

		WriteUInt32ToBinary(outputFileStream, mT3MeshDataBlockSize);
		WriteUInt32ToBinary(outputFileStream, mLODs_ArrayCapacity);
		WriteUInt32ToBinary(outputFileStream, mLODs_ArrayLength);

		for (int i = 0; i < mLODs_ArrayLength; i++)
			mLODs[i].BinarySerialize(outputFileStream);

		WriteUInt32ToBinary(outputFileStream, mTextures_ArrayCapacity);
		WriteUInt32ToBinary(outputFileStream, mTextures_ArrayLength);
		WriteByteVectorBufferToBinary(outputFileStream, mTexturesData);

		WriteUInt32ToBinary(outputFileStream, mMaterials_ArrayCapacity);
		WriteUInt32ToBinary(outputFileStream, mMaterials_ArrayLength);

		for (int i = 0; i < mMaterials_ArrayLength; i++)
			mMaterials[i].BinarySerialize(outputFileStream);

		WriteUInt32ToBinary(outputFileStream, mMaterialOverrides_ArrayCapacity);
		WriteUInt32ToBinary(outputFileStream, mMaterialOverrides_ArrayLength);
		WriteByteVectorBufferToBinary(outputFileStream, mMaterialOverridesData);

		WriteUInt32ToBinary(outputFileStream, mBones_ArrayCapacity);
		WriteUInt32ToBinary(outputFileStream, mBones_ArrayLength);

		for (int i = 0; i < mBones_ArrayLength; i++)
			mBones[i].BinarySerialize(outputFileStream);

		WriteUInt32ToBinary(outputFileStream, mLocalTransforms_ArrayCapacity);
		WriteUInt32ToBinary(outputFileStream, mLocalTransforms_ArrayLength);

		for (int i = 0; i < mLocalTransforms_ArrayLength; i++)
			mLocalTransforms[i].BinarySerialize(outputFileStream);

		mMaterialRequirements.BinarySerialize(outputFileStream);
		WriteUInt32ToBinary(outputFileStream, mVertexStreams_BlockSize);
		WriteUInt32ToBinary(outputFileStream, mVertexStreams);
		mBoundingBox.BinarySerialize(outputFileStream);
		mBoundingSphere.BinarySerialize(outputFileStream);
		WriteUInt32ToBinary(outputFileStream, mEndianType);
		mPositionScale.BinarySerialize(outputFileStream);
		mPositionWScale.BinarySerialize(outputFileStream);
		mPositionOffset.BinarySerialize(outputFileStream);
		WriteFloat32ToBinary(outputFileStream, mLightmapTexelAreaPerSurfaceArea);
		mPropertyKeyBase.BinarySerialize(outputFileStream);
		WriteUInt32ToBinary(outputFileStream, mVertexCount);
		WriteUInt32ToBinary(outputFileStream, mFlags);

		WriteUInt32ToBinary(outputFileStream, mMeshPreload_ArrayCapacity);
		WriteUInt32ToBinary(outputFileStream, mMeshPreload_ArrayLength);

		for (int i = 0; i < mMeshPreload_ArrayLength; i++)
			mMeshPreload[i].BinarySerialize(outputFileStream);

		WriteUInt32ToBinary(outputFileStream, mUVLayersCount);
		WriteUInt32ToBinary(outputFileStream, UNKNOWN2);
		WriteUInt32ToBinary(outputFileStream, mVertexCountPerInstance);
		WriteUInt32ToBinary(outputFileStream, mIndexBufferCount);
		WriteUInt32ToBinary(outputFileStream, mVertexBufferCount);
		WriteUInt32ToBinary(outputFileStream, mAttributeCount);

		for (int i = 0; i < mAttributeCount; i++)
			GFXPlatformAttributeParamsArray[i].BinarySerialize(outputFileStream);

		for (int i = 0; i < mIndexBufferCount; i++)
			mIndexBuffers[i].BinarySerialize(outputFileStream);

		for (int i = 0; i < mVertexBufferCount; i++)
			mVertexBuffers[i].BinarySerialize(outputFileStream);
	};

	//||||||||||||||||||||||||||||| TO STRING |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| TO STRING |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| TO STRING |||||||||||||||||||||||||||||

	std::string ToString() const
	{
		std::string output = "";
		output += "[TelltaleD3DMeshHeaderV55] mNameBlockSize: " + std::to_string(mNameBlockSize) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mName: " + mName + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mVersion: " + std::to_string(mVersion) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mToolProps: " + std::to_string(mToolProps) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mLightmapGlobalScale: " + std::to_string(mLightmapGlobalScale) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mLightmapTexCoordVersion: " + std::to_string(mLightmapTexCoordVersion) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mLODParamCRC: " + mLODParamCRC.ToString() + "\n";
		output += "[TelltaleD3DMeshHeaderV55] ============ TelltaleInternalResource ARRAY START ============ \n";

		for (int i = 0; i < mInternalResourcesCount; i++)
		{
			output += "[TelltaleD3DMeshHeaderV55] ============ TelltaleInternalResource " + std::to_string(i) + " ============ \n";
			output += mInternalResources[i].ToString() + "\n";
		}

		output += "[TelltaleD3DMeshHeaderV55] ============ TelltaleInternalResource ARRAY END ============ \n";
		output += "[TelltaleD3DMeshHeaderV55] mToolPropsBlockSize: " + std::to_string(mToolPropsBlockSize) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mToolPropsData [" + std::to_string(mToolPropsBlockSize - 4) + " BYTES] \n";
		output += "[TelltaleD3DMeshHeaderV55] mHasOcclusionData: " + std::to_string(mHasOcclusionData) + "\n";

		//if this is true then we need to skip it (ASCII '1' is true, ASCII '0' is false)
		if (mHasOcclusionData == '1')
		{
			output += "[TelltaleD3DMeshHeaderV55] mOcclusionDataBlockSize: " + std::to_string(mOcclusionDataBlockSize) + "\n";
			output += "[TelltaleD3DMeshHeaderV55] mOcclusionData [" + std::to_string(mOcclusionDataBlockSize - 4) + " BYTES] \n";
		}

		output += "[TelltaleD3DMeshHeaderV55] mT3MeshDataBlockSize: " + std::to_string(mT3MeshDataBlockSize) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mLODs_ArrayCapacity: " + std::to_string(mLODs_ArrayCapacity) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mLODs_ArrayLength: " + std::to_string(mLODs_ArrayLength) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] ============ T3MeshLOD ARRAY START ============ \n";

		for (int i = 0; i < mLODs_ArrayLength; i++)
		{
			output += "[TelltaleD3DMeshHeaderV55] ============ T3MeshLOD " + std::to_string(i) + " ============ \n";
			output += mLODs[i].ToString() + "\n";
		}

		output += "[TelltaleD3DMeshHeaderV55] ============ T3MeshLOD ARRAY END ============ \n";
		output += "[TelltaleD3DMeshHeaderV55] mTextures_ArrayCapacity: " + std::to_string(mTextures_ArrayCapacity) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mTextures_ArrayLength: " + std::to_string(mTextures_ArrayLength) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mTexturesData [" + std::to_string(mTextures_ArrayCapacity - 8) + " BYTES] \n";
		output += "[TelltaleD3DMeshHeaderV55] mMaterials_ArrayCapacity: " + std::to_string(mMaterials_ArrayCapacity) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mMaterials_ArrayLength: " + std::to_string(mMaterials_ArrayLength) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mMaterials [" + std::to_string(mMaterials_ArrayCapacity - 8) + " BYTES] \n";
		output += "[TelltaleD3DMeshHeaderV55] mMaterialOverrides_ArrayCapacity: " + std::to_string(mMaterialOverrides_ArrayCapacity) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mMaterialOverrides_ArrayLength: " + std::to_string(mMaterialOverrides_ArrayLength) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mMaterialOverridesData [" + std::to_string(mMaterialOverrides_ArrayCapacity - 8) + " BYTES] \n";
		output += "[TelltaleD3DMeshHeaderV55] mBones_ArrayCapacity: " + std::to_string(mBones_ArrayCapacity) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mBones_ArrayLength: " + std::to_string(mBones_ArrayLength) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] ============ T3MeshBoneEntry ARRAY START ============ \n";

		for (int i = 0; i < mBones_ArrayLength; i++)
		{
			output += "[TelltaleD3DMeshHeaderV55] ============ T3MeshBoneEntry " + std::to_string(i) + " ============ \n";
			output += mBones[i].ToString() + "\n";
		}

		output += "[TelltaleD3DMeshHeaderV55] ============ T3MeshBoneEntry ARRAY END ============ \n";
		output += "[TelltaleD3DMeshHeaderV55] mLocalTransforms_ArrayCapacity: " + std::to_string(mLocalTransforms_ArrayCapacity) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mLocalTransforms_ArrayLength: " + std::to_string(mLocalTransforms_ArrayLength) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] ============ T3MeshLocalTransformEntry ARRAY START ============ \n";

		for (int i = 0; i < mLocalTransforms_ArrayLength; i++)
		{
			output += "[TelltaleD3DMeshHeaderV55] ============ T3MeshLocalTransformEntry " + std::to_string(i) + " ============ \n";
			output += mLocalTransforms[i].ToString() + "\n";
		}

		output += "[TelltaleD3DMeshHeaderV55] ============ T3MeshLocalTransformEntry ARRAY END ============ \n";
		output += "[TelltaleD3DMeshHeaderV55] mMaterialRequirements: " + mMaterialRequirements.ToString() + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mVertexStreams_BlockSize: " + std::to_string(mVertexStreams_BlockSize) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mVertexStreams: " + std::to_string(mVertexStreams) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mBoundingBox: " + mBoundingBox.ToString() + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mBoundingSphere: " + mBoundingSphere.ToString() + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mEndianType: " + std::to_string(mEndianType) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mPositionScale: " + mPositionScale.ToString() + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mPositionWScale: " + mPositionWScale.ToString() + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mPositionOffset: " + mPositionOffset.ToString() + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mLightmapTexelAreaPerSurfaceArea: " + std::to_string(mLightmapTexelAreaPerSurfaceArea) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mPropertyKeyBase: " + mPropertyKeyBase.ToString() + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mVertexCount: " + std::to_string(mVertexCount) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mFlags: " + std::to_string(mFlags) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mMeshPreload_ArrayCapacity: " + std::to_string(mMeshPreload_ArrayCapacity) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mMeshPreload_ArrayLength: " + std::to_string(mMeshPreload_ArrayLength) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] ============ T3MeshEffectPreload ARRAY START ============ \n";

		for (int i = 0; i < mMeshPreload_ArrayLength; i++)
		{
			output += "[TelltaleD3DMeshHeaderV55] ============ T3MeshEffectPreload " + std::to_string(i) + " ============ \n";
			output += mMeshPreload[i].ToString() + "\n";
		}

		output += "[TelltaleD3DMeshHeaderV55] ============ T3MeshEffectPreload ARRAY END ============ \n";
		output += "[TelltaleD3DMeshHeaderV55] mUVLayersCount: " + std::to_string(mUVLayersCount) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] UNKNOWN2: " + std::to_string(UNKNOWN2) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mVertexCountPerInstance: " + std::to_string(mVertexCountPerInstance) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mIndexBufferCount: " + std::to_string(mIndexBufferCount) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mVertexBufferCount: " + std::to_string(mVertexBufferCount) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] mAttributeCount: " + std::to_string(mAttributeCount) + "\n";
		output += "[TelltaleD3DMeshHeaderV55] ============ GFXPlatformAttributeParams ARRAY START ============ \n";

		for (int i = 0; i < mAttributeCount; i++)
		{
			output += "[TelltaleD3DMeshHeaderV55] ============ GFXPlatformAttributeParams " + std::to_string(i) + " ============ \n";
			output += GFXPlatformAttributeParamsArray[i].ToString() + "\n";
		}

		output += "[TelltaleD3DMeshHeaderV55] ============ GFXPlatformAttributeParams ARRAY END ============ \n";
		output += "[TelltaleD3DMeshHeaderV55] ============ T3GFXBuffer ARRAY START ============ \n";

		for (int i = 0; i < mIndexBufferCount; i++)
		{
			output += "[TelltaleD3DMeshHeaderV55] ============ T3GFXBuffer " + std::to_string(i) + " ============ \n";
			output += mIndexBuffers[i].ToString() + "\n";
		}

		output += "[TelltaleD3DMeshHeaderV55] ============ T3GFXBuffer ARRAY END ============ \n";
		output += "[TelltaleD3DMeshHeaderV55] ============ T3GFXBuffer ARRAY START ============ \n";

		for (int i = 0; i < mVertexBufferCount; i++)
		{
			output += "[TelltaleD3DMeshHeaderV55] ============ T3GFXBuffer " + std::to_string(i) + " ============ \n";
			output += mVertexBuffers[i].ToString() + "\n";
		}

		output += "[TelltaleD3DMeshHeaderV55] ============ T3GFXBuffer ARRAY END ============";

		return output;
	};

	//||||||||||||||||||||||||||||| JSON |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| JSON |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| JSON |||||||||||||||||||||||||||||
	//REFERENCE - https://json.nlohmann.me/features/arbitrary_types/
	//NOTE: These macros are limited to 64 members at most (if there are more you'll need to implement manually.

	//These are supposed to be inside the class/struct
	//NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(...) //will not throw exceptions, fills in values with default constructor
	NLOHMANN_ORDERED_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(
		TelltaleD3DMeshHeaderV55,
		mNameBlockSize, //1
		mName, //2
		mVersion, //3
		mToolProps, //4
		mLightmapGlobalScale, //5
		mLightmapTexCoordVersion, //6
		mLODParamCRC, //7
		mInternalResourcesCount, //8
		mInternalResources, //9
		mToolPropsBlockSize, //10
		mToolPropsData, //11
		mHasOcclusionData, //12
		mOcclusionDataBlockSize, //13
		mOcclusionData, //14
		mT3MeshDataBlockSize, //15
		mLODs_ArrayCapacity, //16
		mLODs_ArrayLength, //17
		mLODs, //18
		mTextures_ArrayCapacity, //19
		mTextures_ArrayLength, //20
		mTexturesData, //21
		mMaterials_ArrayCapacity, //22
		mMaterials_ArrayLength, //23
		mMaterials, //24
		mMaterialOverrides_ArrayCapacity, //25
		mMaterialOverrides_ArrayLength, //26
		mMaterialOverridesData, //27
		mBones_ArrayCapacity, //28
		mBones_ArrayLength, //29
		mBones, //30
		mLocalTransforms_ArrayCapacity, //31
		mLocalTransforms_ArrayLength, //32
		mLocalTransforms, //33
		mMaterialRequirements, //34
		mVertexStreams_BlockSize, //35
		mVertexStreams, //36
		mBoundingBox, //37
		mBoundingSphere, //38
		mEndianType, //39
		mPositionScale, //40
		mPositionWScale, //41
		mPositionOffset, //42
		mLightmapTexelAreaPerSurfaceArea, //43
		mPropertyKeyBase, //44
		mVertexCount, //45
		mFlags, //46
		mMeshPreload_ArrayCapacity, //47
		mMeshPreload_ArrayLength, //48
		mMeshPreload, //49
		mUVLayersCount, //50
		UNKNOWN2, //51
		mVertexCountPerInstance, //52
		mIndexBufferCount, //53
		mVertexBufferCount, //54
		mAttributeCount, //55
		GFXPlatformAttributeParamsArray, //56
		mIndexBuffers, //57
		mVertexBuffers) //58

	//||||||||||||||||||||||||||||| BYTE SIZE |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| BYTE SIZE |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| BYTE SIZE |||||||||||||||||||||||||||||
	//NOTE: Yes I'm aware that C++ has functionality/operators for returning the size of the object, however...
	//For some of these structs/classes the size C++ returns/gets is wrong and doesn't match what telltale would expect.
	//So for saftey I will just manually calculate the byte size of the object here to what telltale expects.

	unsigned int GetT3MeshDataByteSize() 
	{
		//NOTE: In binary we seem to be off by only 4 bytes... unable to track down at the moment what is wrong but universally all output files are missing 4 suppsoed bytes.
		//For the time being intead of starting at 0 here we will start at 4.
		unsigned int totalByteSize = 4;
		totalByteSize += 4; //[4 BYTES] mLODs_ArrayCapacity
		totalByteSize += 4; //[4 BYTES] mLODs_ArrayLength

		for (int i = 0; i < mLODs_ArrayLength; i++) //mLODs
			totalByteSize += mLODs[i].GetByteSize(); //[x BYTES]

		totalByteSize += 4; //[4 BYTES] mTextures_ArrayCapacity
		totalByteSize += 4; //[4 BYTES] mTextures_ArrayLength
		totalByteSize += mTextures_ArrayCapacity - 8; //[x BYTES] mTexturesData
		totalByteSize += 4; //[4 BYTES] mMaterials_ArrayCapacity
		totalByteSize += 4; //[4 BYTES] mMaterials_ArrayLength

		for (int i = 0; i < mMaterials_ArrayLength; i++) //mMaterials
			totalByteSize += mMaterials[i].GetByteSize(); //[76 BYTES]

		totalByteSize += 4; //[4 BYTES] mMaterialOverrides_ArrayCapacity
		totalByteSize += 4; //[4 BYTES] mMaterialOverrides_ArrayLength
		totalByteSize += mMaterialOverrides_ArrayCapacity - 8; //[x BYTES] mMaterialOverridesData
		totalByteSize += 4; //[4 BYTES] mBones_ArrayCapacity
		totalByteSize += 4; //[4 BYTES] mBones_ArrayLength

		for (int i = 0; i < mBones_ArrayLength; i++) //mBones
			totalByteSize += mBones[i].GetByteSize(); //[x BYTES]

		totalByteSize += 4; //[4 BYTES] mLocalTransforms_ArrayCapacity
		totalByteSize += 4; //[4 BYTES] mLocalTransforms_ArrayLength

		for (int i = 0; i < mLocalTransforms_ArrayLength; i++) //mLocalTransforms
			totalByteSize += mLocalTransforms[i].GetByteSize(); //[x BYTES]

		totalByteSize += mMaterialRequirements.GetByteSize(); //[40 BYTES] mMaterialRequirements
		totalByteSize += 4; //[4 BYTES] mVertexStreams_BlockSize
		totalByteSize += 4; //[4 BYTES] mVertexStreams
		totalByteSize += mBoundingBox.GetByteSize(); //[24 BYTES] mBoundingBox
		totalByteSize += mBoundingSphere.GetByteSize(); //[20 BYTES] mBoundingSphere
		totalByteSize += 4; //[4 BYTES] mEndianType
		totalByteSize += mPositionScale.GetByteSize(); //[12 BYTES] mPositionScale
		totalByteSize += mPositionWScale.GetByteSize(); //[12 BYTES] mPositionWScale
		totalByteSize += mPositionOffset.GetByteSize(); //[12 BYTES] mPositionOffset
		totalByteSize += 4; //[4 BYTES] mLightmapTexelAreaPerSurfaceArea
		totalByteSize += mPropertyKeyBase.GetByteSize(); //[8 BYTES] mPropertyKeyBase
		totalByteSize += 4; //[4 BYTES] mVertexCount
		totalByteSize += 4; //[4 BYTES] mFlags
		totalByteSize += 4; //[4 BYTES] mMeshPreload_ArrayCapacity
		totalByteSize += 4; //[4 BYTES] mMeshPreload_ArrayLength

		for (int i = 0; i < mMeshPreload_ArrayLength; i++) //mMeshPreload
			totalByteSize += mMeshPreload[i].GetByteSize(); //[x BYTES]

		totalByteSize += 4; //[4 BYTES] UNKNOWN1
		totalByteSize += 4; //[4 BYTES] UNKNOWN2
		totalByteSize += 4; //[4 BYTES] mVertexCountPerInstance
		totalByteSize += 4; //[4 BYTES] mIndexBufferCount
		totalByteSize += 4; //[4 BYTES] mVertexBufferCount
		totalByteSize += 4; //[4 BYTES] mAttributeCount

		for (int i = 0; i < mAttributeCount; i++) //GFXPlatformAttributeParamsArray
			totalByteSize += GFXPlatformAttributeParamsArray[i].GetByteSize(); //[20 BYTES]

		for (int i = 0; i < mIndexBufferCount; i++) //mIndexBuffers
			totalByteSize += mIndexBuffers[i].GetByteSize(); //[20 BYTES]

		for (int i = 0; i < mVertexBufferCount; i++) //mVertexBuffers
			totalByteSize += mVertexBuffers[i].GetByteSize(); //[20 BYTES]

		return totalByteSize;
	}

	/// <summary>
	/// [x BYTES]
	/// </summary>
	/// <returns></returns>
	unsigned int GetByteSize()
	{
		unsigned int totalByteSize = 0;
		totalByteSize += 4; //[4 BYTES] mNameBlockSize
		totalByteSize += 4; //[4 BYTES] mNameLength
		totalByteSize += mName.length(); //[x BYTES] mName
		totalByteSize += 4; //[4 BYTES] mVersion
		totalByteSize += 1; //[1 BYTE] mToolProps
		totalByteSize += 4; //[4 BYTES] mLightmapGlobalScale
		totalByteSize += 4; //[4 BYTES] mLightmapTexCoordVersion
		totalByteSize += mLODParamCRC.GetByteSize(); //[8 BYTES] mLODParamCRC
		totalByteSize += 4; //[4 BYTES] mInternalResourcesCount

		for (int i = 0; i < mInternalResourcesCount; i++)
			totalByteSize += mInternalResources[i].GetByteSize(); //[x BYTES] mInternalResource

		totalByteSize += 4; //[4 BYTES] mToolPropsBlockSize
		totalByteSize += mToolPropsBlockSize - 4; //[x BYTES] mToolPropsData
		totalByteSize += 1; //[1 BYTE] mHasOcclusionData

		//if this is true then we need to skip it (ASCII '1' is true, ASCII '0' is false)
		if (mHasOcclusionData == '1')
		{
			totalByteSize += 4; //[4 BYTES] mOcclusionDataBlockSize
			totalByteSize += mOcclusionDataBlockSize - 4; //[x BYTES] mOcclusionData
		}

		totalByteSize += 4; //[4 BYTES] mT3MeshDataBlockSize
		totalByteSize += GetT3MeshDataByteSize();
		return totalByteSize;
	}

	unsigned int GetD3DMeshDataSize()
	{
		unsigned int totalByteSize = 0;

		for (int i = 0; i < mIndexBuffers.size(); i++)
			totalByteSize += mIndexBuffers[i].mCount * mIndexBuffers[i].mStride;

		for (int i = 0; i < mVertexBuffers.size(); i++)
			totalByteSize += mVertexBuffers[i].mCount * mVertexBuffers[i].mStride;

		return totalByteSize;
	}
};


#endif