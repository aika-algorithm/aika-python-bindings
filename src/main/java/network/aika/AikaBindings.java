package network.aika;

import network.aika.type.Obj;
import network.aika.type.Type;
import network.aika.type.TypeRegistry;
import network.aika.type.TypeRegistryImpl;
import org.graalvm.nativeimage.IsolateThread;
import org.graalvm.nativeimage.c.function.CEntryPoint;
import org.graalvm.nativeimage.c.type.CCharPointer;
import org.graalvm.nativeimage.c.type.CTypeConversion;

import java.util.List;

public class AikaBindings {

    // Method to return a greeting message
    @CEntryPoint(name = "greet")
    public static CCharPointer greet(IsolateThread thread, CCharPointer cFilter) {
        String input = CTypeConversion.toJavaString(cFilter);
        String result = "Hello, " + new String(input) + "!";

        TypeRegistry registry = new TypeRegistryImpl();
        Type type = new Type(registry, input);

        return CTypeConversion.toCString(type.toString()).get();
    }
}
