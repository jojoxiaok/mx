// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/Shake.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        Shake::Shake()
        :ElementInterface()
        ,myAttributes( std::make_shared<EmptyTrillSoundAttributes>() )
        {}


        bool Shake::hasAttributes() const
        {
            return myAttributes->hasValues();
        }


        bool Shake::hasContents() const  { return false; }
        std::ostream& Shake::streamAttributes( std::ostream& os ) const
        {
            if ( myAttributes )
            {
                myAttributes->toStream( os );
            }
            return os;
        }


        std::ostream& Shake::streamName( std::ostream& os ) const  { os << "shake"; return os; }
        std::ostream& Shake::streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const
        {
            MX_UNUSED( indentLevel );
            isOneLineOnly = true;
            return os;
        }


        EmptyTrillSoundAttributesPtr Shake::getAttributes() const
        {
            return myAttributes;
        }


        void Shake::setAttributes( const EmptyTrillSoundAttributesPtr& value )
        {
            if ( value )
            {
                myAttributes = value;
            }
        }


        bool Shake::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            return myAttributes->fromXElement( message, xelement );
        }

    }
}
