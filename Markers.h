#pragma once

//#include <cinder/app/AppBase.h>
//#include <cinder/gl/gl.h>
#include <string>

namespace ph {

class Marker {
  public:
	static void swap() { id = 0; }
	static void push( const char *message )
	{
		//if( !ci::app::isMainThread() )
		//	throw std::logic_error( "Markers can only be pushed from the main thread!" );

		glPushDebugGroup( GL_DEBUG_SOURCE_APPLICATION, id++, -1, message );
	}
	static void pop()
	{
		//if( !ci::app::isMainThread() )
		//	throw std::logic_error( "Markers can only be popped from the main thread!" );

		glPopDebugGroup();
	}

  private:
	Marker() = default;

	__declspec( thread ) static int id;
};

class ScopedMarker {
  public:
	explicit ScopedMarker( const char *message ) { Marker::push( message ); }
	explicit ScopedMarker( std::string message ) { Marker::push( message.c_str() ); }
	~ScopedMarker() { Marker::pop(); }
};

} // namespace ph
