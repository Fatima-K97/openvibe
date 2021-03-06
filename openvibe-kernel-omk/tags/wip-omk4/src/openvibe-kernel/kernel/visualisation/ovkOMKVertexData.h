#ifndef OMK_VertexData_H
#define OMK_VertexData_H
/*
#include "Wm4Vector3.h"
#include "Wm4Vector4.h"*/
#include <openvibe/ov_all.h>
#include "OMKTracer.h"
#include <iostream>

//#define ALLOCATE_VERTEX_DATA_MEMORY
//#define SHARE_MEMORY_WITH_CALLER
#define USE_STL_CONTAINERS

namespace OMK  
{
class OutgoingSynchronisationMessage ;
class IncomingSynchronisationMessage ;

namespace Type 
{
class /*OMK_API*/ VertexData
{
public:
	/*
	enum EVertexDataAction
	{
		VertexDataAction_None=0,
		VertexDataAction_Set,
		VertexDataAction_Get
	};*/

  /// @name Constructors and destructor.
  //@{
  ///\brief Default constructor of \ref VertexData.  
  VertexData() ;
  
  ///\brief Destructor of \ref VertexData.
  virtual ~VertexData() ;
  //@}

	///\brief Destroys dynamically allocated memory, if any 
	/// FIXME : for now, it is up to the programmer to call this method when necessary
	void cleanup();
  
	///\brief Set vertices action
	//void setVerticesAction( EVertexDataAction action );		
	
	///\brief Set vertices		
	//void setVertices( const std::vector< Wm4::Vector3f >& vertices );
	void setVertexPositionArray( OpenViBE::uint32 ui32VertexPositionCount, const OpenViBE::float32* pVertexPositionArray );

	///\brief Get vertices action
	//EVertexDataAction getVerticesAction();		
	
	///\brief Returns the vector of vertices.
  /// \return The vector of vertices.	
	//const std::vector< Wm4::Vector3f >& getVertices() const ;
	void getVertexPositionArray( OpenViBE::uint32& ui32VertexPositionCount, const OpenViBE::float32*& pVertexPositionArray) const;

	///\brief Set colors action
	//void setColorsAction( EVertexDataAction );	
	
	///\brief Set colors	
	//void setColors( const std::vector< Wm4::Vector4f >& colors );
	void setVertexColorArray( OpenViBE::uint32 ui32VertexColorCount, const OpenViBE::float32* pVertexColorArray );

	///\brief Get colors action
	//EVertexDataAction getColorsAction();	
	
	///\brief Returns the vector of colors.
  /// \return The vector of colors.
	//const std::vector< Wm4::Vector4f >& getColors() const ;
	void getVertexColorArray( OpenViBE::uint32& ui32VertexColorCount, const OpenViBE::float32*& pVertexColorArray) const;

  ///\brief Empty vertex data.
  //static const VertexData sk_default ;

  /// equality operator
  friend /*OMK_API*/ bool operator == ( const VertexData& vd0, const VertexData& vd1 ) ;

  /// inequality operator
  friend /*OMK_API*/ bool operator != ( const VertexData& vd0, const VertexData& vd1 ) ;

  /// @name Friend stream operators.
  //@{
  ///\brief stream operator for ostream.
  /// Use by \ref SimpleTypeT::insertInStream.
  friend /*OMK_API*/ std::ostream& operator << ( std::ostream& out, const VertexData& vd ); 

  ///\brief stream operator for istream.
  /// Use by \ref SimpleTypeT::extract.
  friend /*OMK_API*/ std::istream& operator >> ( std::istream& in, VertexData& vd ) ;

  ///\brief stream operator for OutgoingSynchronisationMessage.
  /// Use by \ref SimpleTypeT::pack.
  friend /*OMK_API*/ OutgoingSynchronisationMessage& operator << 
    ( OutgoingSynchronisationMessage& out, const VertexData& vd ) ;

  ///\brief stream operator for IncomingSynchronisationMessage.
  /// Use by \ref SimpleTypeT::unpack.
  friend /*OMK_API*/ IncomingSynchronisationMessage& operator >> 
    ( IncomingSynchronisationMessage& in, VertexData& vd ) ;
  //@}

private:
	///\brief Vertices information 
	//EVertexDataAction _verticesAction;	
	//std::vector< Wm4::Vector3f > _vertices ;
	OpenViBE::uint32 m_ui32VertexPositionCount;
#ifdef ALLOCATE_VERTEX_DATA_MEMORY
	OpenViBE::float32* m_pVertexPositionArray;
#endif
#ifdef SHARE_MEMORY_WITH_CALLER
	const OpenViBE::float32* m_pVertexPositionArray;
#endif
#ifdef USE_STL_CONTAINERS
	std::vector<OpenViBE::float32> m_pVertexPositionArray;
#endif

	///\brief Color information 
	//EVertexDataAction _colorsAction;
	//std::vector< Wm4::Vector4f > _colors ;
	OpenViBE::uint32 m_ui32VertexColorCount;
#ifdef ALLOCATE_VERTEX_DATA_MEMORY
	OpenViBE::float32* m_pVertexColorArray;
#endif
#ifdef SHARE_MEMORY_WITH_CALLER
	const OpenViBE::float32* m_pVertexColorArray;
#endif
#ifdef USE_STL_CONTAINERS
	std::vector<OpenViBE::float32> m_pVertexColorArray;
#endif
} ;

}// namespace Type
}// namespace OMK

#endif // OMK_VertexData_H
