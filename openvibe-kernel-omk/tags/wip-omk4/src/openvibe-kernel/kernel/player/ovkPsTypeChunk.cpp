///12/09/2006at18:00:29/// Time signature, do not change this line

/************************************************************************/
/* This file is part of openMask(c) INRIA, CNRS, Universite de Rennes 1 */
/* 1993-2002, thereinafter the Software                                 */
/*                                                                      */
/* The Software has been developped within the Siames Project.          */
/* INRIA, the University of Rennes 1 and CNRS jointly hold intellectual */
/* property rights                                                      */
/*                                                                      */
/* The Software has been registered with the Agence pour la Protection  */
/* des Programmes (APP) under registration number                       */
/* IDDN.FR.001.510008.00.S.P.2001.000.41200                             */
/*                                                                      */
/* This file may be distributed under the terms of the Q Public License */
/* version 1.0 as defined by Trolltech AS of Norway and appearing in    */
/* the file LICENSE.QPL included in the packaging of this file.         */
/*                                                                      */
/* Licensees holding valid specific licenses issued by INRIA, CNRS or   */
/* Universite Rennes 1 for the software may use this file in            */
/* acordance with that specific license                                 */
/************************************************************************/
/************************************************************************/
/* WARNING : GENERATED FILE. DO NOT MODIFY IT.                          */
/* Generated the 2006-09-12 at 18:00:29                                 */
/* Generated by omk version 1.2.0                                       */
/* Use just as it is or derive this class to add the  necessary         */
/* functions.                                                           */
/************************************************************************/
/************************************************************************/

#include "ovkPsTypeChunk.h"
#include <OMKSimulatedObject.h>
#include <OMKParametersAccessor.h>
#include <OMKOutgoingSynchronisationMessage.h>
#include <OMKIncomingSynchronisationMessage.h>
#include <OMKPolator.h>
#include <vector>
#include <string>
#include <iostream>

using namespace OpenViBE;
using namespace OpenViBE::Kernel;

#define _ov_stream_func_(TypeName) \
	namespace OMK { \
		template <> OMK::OutgoingSynchronisationMessage& OutgoingSynchronisationMessage::operator << (const TypeName& rValue) { getOutputStream() << rValue; return *this; } \
		template <> OMK::IncomingSynchronisationMessage& IncomingSynchronisationMessage::operator >> (      TypeName& rValue) { getInputStream () >> rValue; return *this; } \
	}

_ov_stream_func_(uint64)
_ov_stream_func_(int64)
_ov_stream_func_(uint32)
_ov_stream_func_(int32)
_ov_stream_func_(uint16)
_ov_stream_func_(int16)
_ov_stream_func_(uint8)
_ov_stream_func_(int8)

_ov_stream_func_(float32)
_ov_stream_func_(float64)
_ov_stream_func_(float80)

_ov_stream_func_(boolean)

#undef _ov_stream_func_

std::ostream& operator <<(std::ostream& rStream, const CBuffer& rBuffer)
{
	rStream<<rBuffer.getSize();
	for(uint64 i=0; i<rBuffer.getSize(); i++)
	{
		rStream<<rBuffer.getDirectPointer()[i];
	}
	return rStream;
}

std::istream& operator>>(std::istream& rStream, CBuffer& rBuffer)
{
	uint64 l_ui64Size;
	rStream>>l_ui64Size;
	//FIXME : should the discard flag be set here???
	rBuffer.setSize(l_ui64Size, false);
	for(uint32 i=0; i<l_ui64Size; i++)
	{
		rStream>>rBuffer.getDirectPointer()[i];
	}
	return rStream;
}

OMK::OutgoingSynchronisationMessage& operator<<(OMK::OutgoingSynchronisationMessage& rStream, const CBuffer& rBuffer)
{
	rStream<<rBuffer.getSize();
	for(uint64 i=0; i<rBuffer.getSize(); i++)
	{
		rStream<<rBuffer.getDirectPointer()[i];
	}
	return rStream;
}

OMK::IncomingSynchronisationMessage& operator>>(OMK::IncomingSynchronisationMessage& rStream, CBuffer& rBuffer)
{
	uint64 l_ui64Size;
	rStream>>l_ui64Size;
	//FIXME : should the discard flag be set here???
	rBuffer.setSize(l_ui64Size, false);
	for(uint32 i=0; i<l_ui64Size; i++)
	{
		rStream>>rBuffer.getDirectPointer()[i];
	}
	return rStream;
}

//========================================================================
// Default constructor
CTypeChunk::CTypeChunk()
: Base(),
	m_bDeprecated(false)
{
}

//========================================================================
// Copy constructor
CTypeChunk::CTypeChunk( const CTypeChunk& ref )
: Base(),
	m_bDeprecated(false)
{
  _copy( ref ) ;
}

//========================================================================
// Constructor with the parameters
CTypeChunk::CTypeChunk( uint32 ioConnectorIndex,
                            uint64 startTime,
                            uint64 endTime,
                            const CBuffer& buffer)
: Base(),
	_ioConnectorIndex( ioConnectorIndex ) ,
	_startTime( startTime ) ,
	_endTime( endTime ) ,
	_buffer( buffer ) ,
	m_bDeprecated(false)
{
}

//========================================================================
// Destructor
CTypeChunk::~CTypeChunk()
{
}

//========================================================================
// Default values for parameters
void CTypeChunk::resetDefaultValues()
{
	//=== Reset default parameters
	// No parameters to reset => Nothing to do
}

#if 0

//========================================================================
// Configuration parameters loader
bool CTypeChunk::loadParameters( SimulatedObject* p, const std::string& prefix )
{
	// Get the configuration parameter node of the user param in the simulated object
	return loadParameters( p ? p->getConfigurationParameters() : 0, prefix, p ) ;
}

//========================================================================
// Configuration parameters loader
bool CTypeChunk::loadParameters( const ConfigurationParameterDescriptor * node,
                               const std::string& prefix,
                               SimulatedObject* p )
{
	resetDefaultValues() ;
	return innerParametersLoader( node, prefix, p );
}
//========================================================================
// Configuration parameters loader
bool CTypeChunk::innerParametersLoader( const ConfigurationParameterDescriptor * node, const std::string& prefix, SimulatedObject* p )
{
	// Tests the configuration parameter node
	if( !node )
	{ // No valid node => display error message and return false
		std::cerr << ":-( Error in CTypeChunk::innerParametersLoader";
		if( p ) std::cerr << " for object \"" << p->getName().getString()
		                  << "\" (class " << p->getObjectDescriptor().getClass().getString() << ")" ;
		std::cerr << std::endl << ">>> Invalid node" << std::endl ; 
		return false ;
	}

	//=== The optional parameters => no test
	// Load the value of IoConnectorIndex
	ParametersAccessor::get( node, prefix + "IoConnectorIndex", _ioConnectorIndex ) ;
	// Load the value of StartTime
	ParametersAccessor::get( node, prefix + "StartTime", _startTime ) ;
	// Load the value of EndTime
	ParametersAccessor::get( node, prefix + "EndTime", _endTime ) ;
	// Load the value of Buffer
	ParametersAccessor::get( node, prefix + "Buffer", _buffer ) ;

	// No validation requiered, always true if valid node was given
	return true ;
}

#endif

//========================================================================
// != operator
bool CTypeChunk::operator != ( const CTypeChunk& ref ) const
{
	return true;
}

//========================================================================
// copy operator
CTypeChunk& CTypeChunk::operator = ( const CTypeChunk& ref )
{
	if ( this != &ref )
	{
		_copy( ref ) ;
	}
	return *this ;
}

//========================================================================
// insert in stream
void CTypeChunk::insertInStream( std::ostream& out ) const
{
	out << getIoConnectorIndex() << " "
	    << getStartTime() << " "
	    << getEndTime() << " "
	    // << getBuffer() << " "
	    << m_bDeprecated << " "
	    << " " ;
}

//========================================================================
// extract from a stream
void CTypeChunk::extract( std::istream& in )
{
	in >> _ioConnectorIndex
	   >> _startTime
	   >> _endTime
	   // >> _buffer
	   >> m_bDeprecated;
}

//========================================================================
// pack
void CTypeChunk::pack( OMK::OutgoingSynchronisationMessage& out ) const
{
	out << getIoConnectorIndex()
	    << getStartTime()
	    << getEndTime()
	    // << getBuffer()
	    << m_bDeprecated;
}

//========================================================================
// unpack
void CTypeChunk::unpack( OMK::IncomingSynchronisationMessage& in )
{
	in >> _ioConnectorIndex
	   >> _startTime
	   >> _endTime
	   // >> _buffer
	   >> m_bDeprecated;
}

//========================================================================
// create a default polator
OMK::Type::PolatorNT* CTypeChunk::createPolator()
{
	return new OMK::Type::Polator<CTypeChunk>() ;
}

//========================================================================
// Protected copy methods
void CTypeChunk::_copy( const CTypeChunk& ref )
{
	_ioConnectorIndex = ref.getIoConnectorIndex() ;
	_startTime = ref.getStartTime() ;
	_endTime = ref.getEndTime() ;
	_buffer = ref.getBuffer() ;
	m_bDeprecated=ref.m_bDeprecated;
}

//========================================================================
